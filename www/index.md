---
title: Welcome
---

## Introduction

In Kenya, and other Sub-Saharan countries, the maize harvest is often blighted by aflatoxin contracted from a fungus that resides in the soil and grows upon the grains if left unchecked.
This poses significant health and financial issues upon the subsitance an co-operative farmers who rely on the maize harvest for their lives and livelihoods.
The traditional methods of drying the grain are not satisfactory for protecting the grains from the toxin and they do not meet the requirements set out by global health organisations, so this leaves the maize as potentially harmful to consume and low-value if sold.
A method of increasing the speed and effectiveness of the drying process, while also avoiding contact with contaminated soil, would greatly improve the quality and safety of the maize.

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


