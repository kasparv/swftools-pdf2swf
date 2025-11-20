# Changelog

All notable changes to this fork are documented here.

## [0.9.2-pdflibless] - 2025-11-21

- Make pdf2swf and related tools build without a proprietary PDFlib dependency.
- Add a small dummy get_internal() implementation for builds without PDFlib, so SWF->PDF-only code paths still link.
- Adjust pdf-related device/header code so swfrender and friends link cleanly on modern toolchains.
- Add a basic GitHub Actions workflow to ensure the project builds on Ubuntu with only open-source dependencies.
