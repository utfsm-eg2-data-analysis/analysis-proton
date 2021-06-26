Installation from zero
===========================

1. First, you need to have **ROOT** installed. For example, in the **USM cluster**, you only need to modify your `~/.bashrc` file, and add this line:

   ```
   source /opt/software/root/6.18.04/bin/thisroot.sh
   ```
  
   After doing this, don't forget to reload your **bash** session, by doing `source ~/.bashrc` or by closing and opening the terminal.

2. You also need the package **xutils-dev**. If you're on the **USM cluster**, you don't have to worry about this. Otherwise, in your **local computer**, you can easily check if its installed by doing:

   ```
   apt list --installed | grep xutils-dev
   ```

   If it's not installed, it's as simple as executing:
  
   ```
   sudo apt install xutils-dev
   ```

3. Then, you need to install **ClasTool**. To do so, please clone the following repositories:

   ```
   git clone http://github.com/utfsm-eg2-data-analysis/ClasTool
   git clone http://github.com/utfsm-eg2-data-analysis/clas_pack
   git clone http://github.com/utfsm-eg2-data-analysis/clas_lib
   ```

4. Once they are cloned, you have to modify your `~/.bashrc` file again, in order to set all the required **environment variables**. You should add the following and change `${TOPDIR}` with the real location where the recently downloaded directories are located. For instance, it could be your `${HOME}` directory.

   ```
   export OS_NAME=`uname`
   export OSNAME=${OS_NAME}
   
   export CLASTOOL=${TOPDIR}/ClasTool
   export CLAS_LIB=${TOPDIR}/clas_lib
   export CLAS_PACK=${TOPDIR}/clas_pack
   
   export PATH=${CLASTOOL}/bin/${OSNAME}:${PATH}
   export ROOT_INCLUDE_PATH=${CLASTOOL}/include:${ROOT_INCLUDE_PATH}
   export LD_LIBRARY_PATH=${CLASTOOL}/slib/${OS_NAME}:${LD_LIBRARY_PATH}
   ```

5. Then, within **ClasTool** directory, compile it by entering `make`. It will take a few minutes...

6. Lastly, you want to make sure of some details:

   * Create an empty text file called `rootlogon.C` in your home directory.
     This file contains the instructions to run at the beginning of each **ROOT** console session.
	 Inside the file, you should add this content:

     ```
     {
       gSystem->Load("libMathMore");
       gSystem->Load("libClasTool");
     }
     ```

   * After saving the `rootlogon.C` file, for this to make effect
     you need to create another empty text file called `.rootrc` in your home directory aswell.
     Which you will fill with this only line:

     ```
     Rint.Logon: ~/rootlogon.C
     ```

   * From **ROOT version 6.14** onwards, it has become necessary to copy all dictionaries files into the dynamic libraries folders `slib/`.
     To prevent the warning messages, inside **ClasTool** directory, run:

     ```
     find . -name *.pcm -exec cp -t ./slib/Linux {} +
     ```

7. Now you're ready to compile **GetSimpleTuple**! To do so, inside **GetSimpleTuple** directory, just execute `make`.
