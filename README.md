# System Software Daemon Assignment

**Version 1.0.0**

This is the repository for my first assignment from a TUD final year module titled System Software

## Contributers 
- Daniel Hederman <danhederman@gmail.com>

## Licence & Copyright

© Dan Hederman, TUD System Software 2019

## CTO Requirements

* The company will have an internal intranet site that is a copy of the live site. Staff make changes to the internal site to see and test them before they go live.
* The website content should be backed up every night.
* The changes to the internal site need to be documented. This includes username, page that was modified along with a timestamp.
* The live site is to be updated based on the changes made to the internal site. This should take place during the night. Only the files that have been changed should be copied over.
* No changes should be permitted during backup/transfer processes.
* If urgent changes need to be made it should be possible to make these changes. 

## System Requirements

The following are the requirements for the assignment as choosen by the module lecturer

* Create a Daemon to continually manage the operation of the requirements of the CTO.
* Identify new or modified site content & log details of who made the changes (this should be a text file stored by the server).
* Maintain a list of site updates.
* Update the live site every night after the backup completes.
* When the backup and transfer completes no user should be permitted to make any changes to the site.
* It should be possible to contact the Daemon and perform a backup at any time.
* A message queue should be implemented to allow all process to report success or failure of the process.
* Error logging and reporting should be included.
* Create a make file to manage the creation of the executables.
