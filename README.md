# SpaceEditor
A lightweight editor that only occupies kilobytes from your storage media.

### How to build?

##### The building requirements are:

- Latest version of Code::Blocks, current latest version is 20.04.
- Build and install latest version of wxWidgets. Current latest version is 3.1.4, which SpaceEditor made with.
- It would be a good thing to have the latest version of GCC.
- Under Code::Blocks' compiler settings, click "Linker settings" tab, and add the following library;
"libwx_gtk3u_richtext-3.0.so" 
(The name of the library is depending on the operating system you have. This name is valid under Linux. I don't know what is its name under the Microsoft Windows and macOS. So, select the rich text library from your libraries folder and link it to GCC.)



#### To-do list:
- Port to macOS and Windows.
- Add font color buttons and paragraph alignment button.

# IMPORTANT BUILD WARNING

When you first open the Code::Blocks project file, rebuild the projects. Otherwise, the program won't compile and terminate with error code -1.
