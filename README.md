# Libfile

libfile is an open source repository designed to shorten the code of fstream, which requires a loop to read all files.

## Usage
#Include fread.h and then use:
libfile::read -> to read a file
libfile::overwrite -> to replace output and file, (but to replace the file it doesn't work yet, I will update this method so that it can replace the file as well)

-for example
libfile::read("<your-file>");
libfile::overwrite("file_1", "file_2");

-Note: Use strings or ""

## Stage
This stage is still under development, so there are still features that have not been added.

## License
See [LICENSE](LICENSE) for license details.