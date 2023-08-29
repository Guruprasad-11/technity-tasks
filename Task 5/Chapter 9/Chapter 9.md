# Chapter 9


1. Relative paths are relative to the current working directory.

2. Absolute paths start with the root folder, such as / or C:\.

3. On Windows, it evaluates to WindowsPath('C:/Users/Al'). On other operating systems, it evaluates to a different kind of Path object but with the same path.

4. The expression 'C:/Users' / 'Al' results in an error, since you can’t use the / operator to join two strings.

5. The os.getcwd() function returns the current working directory. The os.chdir() function changes the current working directory.

6. The . folder is the current folder, and .. is the parent folder.

7. C:\bacon\eggs is the dir name, while spam.txt is the base name.

8. The string 'r' for read mode, 'w' for write mode, and 'a' for append mode

9. An existing file opened in write mode is erased and completely overwritten.

10. The read() method returns the file’s entire contents as a single string value. The readlines() method returns a list of strings, where each string is a line from the file’s contents.

11. A shelf value resembles a dictionary value; it has keys and values, along with keys() and values() methods that work similarly to the dictionary methods of the same names.