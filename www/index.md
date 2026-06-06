---
title: Welcome
---

## Introduction

In Kenya, and other Sub-Saharan countries, the maize harvest is often blighted by aflatoxin contracted from a fungus that resides in the soil and grows upon the grains if left unchecked.
This poses significant health and financial issues upon the subsitance an co-operative farmers who rely on the maize harvest for their lives and livelihoods.
The traditional methods of drying the grain are not satisfactory for protecting the grains from the toxin and they do not meet the requirements set out by global health organisations, so this leaves the maize as potentially harmful to consume and low-value if sold.
A method of increasing the speed and effectiveness of the drying process, while also avoiding contact with contaminated soil, would greatly improve the quality and safety of the maize.

## The SOLARSAFE Prototype

The SOLARSAFE device at Taita Taveta University aims to address issues with the preparation and storage of maize for prevention of aflatoxin contamination by inflating a plastic bag within which the grain is held.
The bag is designed to provide passive heating through the greenhouse effect, and a fan provides a steady flow of air over the maize to draw moisture out of the crop.
A core feature of this setup is its solar panel providing 150W of power to a 12V car battery.

## Our Contribution

The current prototype in Kenya only features passive heating of the air.
Initially, our goal was to provide modifications to the blower element of the prototype to inject extra heat for greater drying ability.
A review of literature lead to the alteration of this aim to reduce the relative humidity of the air being blown into the bag by any means, not just by heating.
Our intention was to experiment with providing power to various different devices and measure their contribution to reducing the relative humidity of the air so that we would suggest devices which could provide the greatest benefit from the limited power available.

### To configure your website:

- The required files to run a basic website are included in the repository. We use here Jekyll to turn markdown files into html that will be automatically updated on the website. The component responsible for this is a GitHub action, which is specified in the folder .github/workflows. There is no need to change this file. However:

- In the settings of your repository, go the section "Pages", and select GitHub Actions in the drop down menu to indicate that this is the way you'd like the webpage to be generated.

- Each time you update the markdown files in the www folder of the repository, it will regenerate the web content. The address of the website will be:

```
https://technology-for-the-poorest-billion.github.io/[your repo name here]
```

- index.md is the root of your website. To link another page from here, located within the www folder, use the following syntax:

```
This is a [link](linkedpage.md) to interesting content.
```

Which results in:

This is a [link](linkedpage.md) to interesting content.

- Pay attention to the header of the markdown files in this section. It contains a title section that you will need to reproduce for each page to render them properly.


