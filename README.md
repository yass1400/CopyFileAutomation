# Copy File Automation
A lightweight demo Application for automatic copying of files of a designated enxtension from a source to a destination directory.
## Review
This app provides an effective solution to copy countless number of filesin the least time.
To make it effective for users I used cxxopts Library. This library provides an environment to structure commands with so called options.

The options used in this app are --source and --extension.
Let's say the targeted directory (source) is "C:/user/source" and the target extension is ".txt", the command will look like this:
```
--source "C:/user/source" --extension ".txt"
```
This way the command becomes more readable and structured.

## Libraries
The application was written in C++ and the libraries that were used are:
- Filesystem
- cxxopts
