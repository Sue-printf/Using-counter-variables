Guidelines on running the Java program
* To run the Java program, ensure that you have the latest JDK installed on your PC.

* Go to the command prompt, and use the command cd to take you to where the java file is. For example, if it is in the Downloads folder, you should use the following command: cd Downloads

* Compile your Java file by using the following command prompt: javac Counter.java

* This will generate a file named Counter.class in the same directory. 

* After compiling, you can run your program with: java Counter
 
* You should get an output that looks like this: Final counter value: 47926300
                                                 Thread1 bonus count: 443700
                                                 Thread2 did 2000000 updates, counter = 47926300

* The above output meets the expected requirements.

Additional Information

* I have also written a C program.

* If you are using windows, download and install Cygwin from its main website and ensure all packages with gcc are installed during the installation process.

* Kindly run the C file first and test it out. If it is correct and meets the requirements, you may use it.

* After successful installation, use the Cygwin terminal to run the counter.c code.

* Use the following commands to run the code: 

  * cd /cygdrive/c/Users/yourpcname/Desktop - This will help you navigate to the file directory.
  * gcc counter.c -o counter - This will compile the counter.c code, creating a counter.exe file in the same directory.
  * ./counter - This should run the code.

* You should get an output that looks like this: Final counter value: 7801600
                                                 Thread1 bonus count: 38400
                                                 Thread2 did 2000000 updates, counter = 7801600

* The above output meets the expected requirements.
