# SpaceEditor
A lightweight text editor.

SpaceEditor is plaintext editor, for now.

### How to build?

##### The building requirements are:

- Latest version of Code::Blocks, current latest version is 20.04.
- Build and install latest version of wxWidgets. Current latest version is 3.1.4, which SpaceEditor made with. Also, do not forget to configure with "--disable-shared" flag. SpaceEditor is statically linked to be able to run on systems that doesn't have wxWidgets compiled.
- It would be a good thing to have the latest version of GCC.
- Under Code::Blocks' compiler settings, click "Linker settings" tab, and add the following library;
"libwx_gtk3u_richtext-3.1.a" 
(The name of the library is depending on the operating system you have. This name is valid under Linux. I don't know what is its name under the Microsoft Windows and macOS. So, select the rich text library from your libraries folder and link it to GCC.)



#### To-do list:
- Port to macOS and Windows.
- Add font color buttons and paragraph alignment button.

### IMPORTANT BUILD WARNINGS

- When you first open the Code::Blocks project file, rebuild the projects. Otherwise, the program won't compile and GCC will terminate with returning -1.
- Please check your building configurations before writing an issue that is related to building.
