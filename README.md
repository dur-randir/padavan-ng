# README #

Welcome to the rt-n56u project (by @Andi Padavan)

This project aims to improve the rt-n56u and other supported devices on the software part, allowing power user to take full control over their hardware.
This project was created in hope to be useful, but comes without warranty or support. Installing it will probably void your warranty.
Contributors of this project are not responsible for what happens next. Flash at your own risk!

### Unofficial changes in this Fork ###

Motivation: I got two good old RT-N56U happily up and running since years with @Andy Padavan firmware (kudos and credits!) and as i plan to still keep them running
at least till my internet modem gets an upgrade to over 1 gigabit i recently felt that i have to update it as the latest official firmware update was from 2018 (development snapshot)
and no changes have been done there since then.

Modification: Sooo i forked the original repo from @Andy Padavan, followed the build instructions and eventually started to do my things... for some weeks... till i was ready and
pleased so far with my 'refreshed' version. In one of my last changes i accidentally found [this repo](https://github.com/Linaro1985/padavan-ng) during investigating stuff which was a better and more up-to-date
version of my 'refresh'. No clue how i could miss that the whole time, but i did! Damn!! :-)

Result: Ok so i made a new plan by going back to start and use this better repo from @Linaro1985 as a base for my refresh and instead carry THIS torch a bit further on.
And here we are now with the result in this repo which contains changes which i (ZaneZam) needed/find useful and which are based on top of the latest commit ([56960f9](https://gitlab.com/padavan-ng/padavan-ng/commit/56960f9cc31cb69e42d06deae4afa4b9b95b0b24)) of the unofficial fork
from @Linaro1985 (project got 'archived' meanwhile!) ready to get used. It contains mainly changes for the RT-N56U which are for example: updated program/library packages, security fixes,
minor webui changes, a lean firmware config 'mini', etc. (details in the changelog, see link below) I will try to keep things updated on a regular basis and maybe some
more improvements will find their way into this fork in the future.

**ATTENTION: Due to lack of other supported devices changes i made are ONLY tested by me on the RT-N56U device! So if these changes are working on other supported devices is unknown!!**

### How do I get set up? ###

* [Get the tools to build the system](https://bitbucket.org/padavan/rt-n56u/wiki/EN/HowToMakeFirmware) or use one of the pre-build images (see below)
* Feed the device with the system image file (Follow instructions of updating your current system in wiki)
* Perform factory reset
* Open web browser on http://my.router to configure the services

### Dokummentation ###

- [Changelog of this Fork](https://github.com/zanezam/padavan-ng/blob/custom/changes.eng.txt)
- [Unofficial Documentation](https://github.com/zanezam/padavan-ng/blob/custom/doc)
- [Official Wiki](https://bitbucket.org/padavan/rt-n56u/wiki/Home)

### Downloads ###

- [Unofficial Stable and Test Builds by ZaneZam](https://github.com/zanezam/padavan-ng/blob/custom/doc/Download.md)
- [Original Stable Builds by Andy padavan](https://bitbucket.org/padavan/rt-n56u/downloads/)
- [Original Nightly Builds by Andy padavan](http://rt-n56u.soulblader.com/files/current/)

### Source ###

- [ZaneZam's Fork](https://github.com/zanezam/padavan-ng)
- [Linaro's Fork](https://gitlab.com/padavan-ng/padavan-ng)
- [Original padavan Source](https://bitbucket.org/padavan/rt-n56u/)

### Contribution ###

Feel free to send in improvements/fixes (but please ONLY for the RT-N56U!!) I'll keep the issue/pull request system open for that purpose.
NOTE: if and when a possible interesting change will get added depends on a verification/test of the particular change and if i have time to do it.

### DISCLAIMER ###
IMPORTANT NOTE!! PLEASE READ IT CAREFULLY!!
# NO WARRANTY OR SUPPORT
This product includes copyrighted third-party software licensed under the terms of the GNU General Public License. Please see The GNU General Public License for the exact terms
and conditions of this license. The firmware or any other product designed or produced by this project may contain in whole or in part pre-release, untested, or not fully tested works.
This may contain errors that could cause failures or loss of data, and may be incomplete or contain inaccuracies. You expressly acknowledge and agree that use of software or any part,
produced by this project, is at Your sole and entire risk.

ANY PRODUCT IS PROVIDED 'AS IS' AND WITHOUT WARRANTY, UPGRADES OR SUPPORT OF ANY KIND. ALL CONTRIBUTORS EXPRESSLY DISCLAIM ALL WARRANTIES AND/OR CONDITIONS, EXPRESS OR IMPLIED,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES AND/OR CONDITIONS OF SATISFACTORY QUALITY, OF FITNESS FOR A PARTICULAR PURPOSE, OF ACCURACY, OF QUIET ENJOYMENT, AND NONINFRINGEMENT
OF THIRD PARTY RIGHTS.