#!/usr/bin/env python3
"""
Read SOLARSAFE Arduino CSV lines from serial and append to a CSV file.

Usage:
  python3 python_logger.py --port /dev/cu.usbmodem2101 --out run_001.csv

Install:
  pip3 install pyserial
"""

import argparse
import csv
import sys
from datetime import datetime, timezone

import serial

CSV_HEADER = [
    "elapsed_ms",
    "inlet_temp_c",
    "inlet_rh_pct",
    "outlet_temp_c",
    "outlet_rh_pct",
    "fan_pct",
    "inlet_ok",
    "outlet_ok",
]


def list_ports():
    import serial.tools.list_ports
    ports = [p.device for p in serial.tools.list_ports.comports()]
    return ports


def parse_data_line(line: str):
    if not line.startswith("DATA,"):
        return None
    parts = line.strip().split(",")
    if len(parts) != 9:
        return None
    return parts[1:]  # drop "DATA" prefix


def main():
    parser = argparse.ArgumentParser(description="Log SOLARSAFE serial data to CSV")
    parser.add_argument("--port", help="Serial port, e.g. /dev/cu.usbmodem1101")
    parser.add_argument("--out", default=None, help="Output CSV path")
    parser.add_argument("--baud", type=int, default=115200)
    args = parser.parse_args()

    if not args.port:
        ports = list_ports()
        if not ports:
            print("No serial ports found.", file=sys.stderr)
            sys.exit(1)
        if len(ports) == 1:
            args.port = ports[0]
            print(f"Using port: {args.port}")
        else:
            print("Multiple ports found. Choose one with --port:")
            for p in ports:
                print(f"  {p}")
            sys.exit(1)

    if args.out is None:
        stamp = datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")
        args.out = f"solarsafe_log_{stamp}.csv"

    print(f"Logging to: {args.out}")
    print("Press Ctrl+C to stop.\n")

    with serial.Serial(args.port, args.baud, timeout=1) as ser, open(
        args.out, "w", newline=""
    ) as f:
        writer = csv.writer(f)
        writer.writerow(CSV_HEADER)
        f.flush()

        try:
            while True:
                raw = ser.readline()
                if not raw:
                    continue
                line = raw.decode("utf-8", errors="replace").strip()
                if not line:
                    continue

                if line.startswith("#"):
                    print(line)
                    continue

                row = parse_data_line(line)
                if row is None:
                    print(f"[skip] {line}")
                    continue

                writer.writerow(row)
                f.flush()
                print(f"[saved] {','.join(row)}")

        except KeyboardInterrupt:
            print(f"\nStopped. Data saved to {args.out}")


if __name__ == "__main__":
    main()