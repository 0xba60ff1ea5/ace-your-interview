#!/bin/sh
# You need this line at the top of every shell script, don't remove it

# This script installs the packages that we need in order for everything in this project to work
# Change into this directory and run with this command : 
# . install.sh

# Print something to the terminal to let the user know where they are
echo Installing New Packages

# This is the list of packages, and the loop to install them
# You might have some of these already, but we'll include them just to make sure
# I don't take credit for this method
# Credit belongs to : https://askubuntu.com/questions/39497/how-to-apt-get-install-multiple-packages-without-stopping-if-not-found
INSTALL_PKGS="g++ gcc git golang-go iptables make nmap python3 python3-tk"
for i in $INSTALL_PKGS; do
  sudo apt-get install -y $i
done

# So why do we need all of these packages? 
#   g++         : Compiles C++ files with the .cpp extention
#   gcc         : Compiles C files with the .c extention
#   git         : Just in case you don't have this, commands for working with git repositories
#   golang-go   : Needed for .go files
#   iptables    : Powerful networking utility, allows you to play with your firewall settings
#   make        : Makefile support, used in large projects to facilitate the building process
#   nmap        : Another powerful networking utility, provides information on host or target systems
#   python3     : Python3 interpreter for, you guessed it, .py files
#   python3-tk  : For importing the tkinter package, provides methods to build a GUI

# docker fwts gvm qemu snap

# Make sure the stuff you just installed is up to date
echo Updating and Upgrading
sudo apt-get update
sudo apt-get upgrade

# And we're done...
echo Done
