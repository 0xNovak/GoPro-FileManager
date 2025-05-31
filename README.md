<h1 align=center>GoPro File Manager</h1>
<p align=center>A comand line interface file manager for go pro videos</p>

Features
--------
- grup renaming
  - while scaning in folder in search of files will ask you to provide a name for entire serie, so you don't have to rename every file yourself
- folder managing
  - all the files will be sorted into folders based on their type.
  - in lrv folder you also will find another mp4 folder with renamed low resolution files.


Usage
--------
- GoPro-FileManager [Main folder name] [flags]
  -flags :
    - -r || --dont-rename    > program will leave all the file names as they are
    - -c || --dont-convert   > program won't create converted lov-res mp4 files
