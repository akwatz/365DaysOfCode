pwd command
cd command

ls - l
Field 1 Field 2 Field 3 Field 4 Field 5 Field 6 Field 7 Field 8 Field 9 Field 10

- rw- r-- r-- 1 root root 209 Mar 30 17:41 printcap

The first field could be

- for File, d for Directory, l for Link

The second,third,fourth fields
Those are permissions that means read, write and execute, and comes in three different fields that belongs to the permission the:
second: The owner has over the file
third: The group has over the file
fourth: Everybody else has over the file

The fifth field
This field specifies the number of links or directories inside this directory.

The sixth field is the user
The user that owns the file, or directory

The seventh field is the group
The group that file belongs to, and any user in that group will have the permissions given in the third field over that file.

The eighth field
The size in bytes, you may modify this by using the -h option together with -l this will have the output in k,M,G for a better understanding.

The ninth field
The date of last modification

The tenth field
The name of the file

-t
sorts the output by last modification date newest first

-h
displays the size of the field in human readable format

-r
reverse the output
