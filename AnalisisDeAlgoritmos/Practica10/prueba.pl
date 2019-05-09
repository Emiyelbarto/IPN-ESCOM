use strict;
use warnings;

# Put the file name in a string variable
# so we can use it both to open the file
# and to refer to in an error message
# if needed.
my $file = "C:/Users/Emiliano/Documents/IPN/AnalisisDeAlgoritmos/Practica10/tmp.txt";

# Use the open() function to open the file.
unless(open FILE, $file) {
    # Die with error message
    # if we can't open it.
    die "\nUnable to open $file\n";
}

# Read the file one line at a time.
while(my $line = <FILE>) {
    # We'll just print the line for now.
    if($line eq "hola\n"){
      print "Aqui hay un hola!\n";
    }
    else{
      print $line;
    }
}

# close the file.
close FILE;
