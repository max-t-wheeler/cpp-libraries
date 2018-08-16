#include <iostream>
#include <stdlib.h>

//plots function using gnuplot
void plot(){

  const char* create_file_chars;
  std::string create_file = "gnome-terminal -x sh -c 'gnuplot -e \"set terminal pngcairo; set output 'output.png'; set title 'test'; set xlabel 'x'; set ylabel 'y'; set xzeroaxis; set yzeroaxis; plot 'data.dat' using 1:2 with lines\" -p'";
  
  create_file_chars = create_file.c_str();
  
  system(create_file_chars);

  const char* open_file_chars;
  std::string file = "output.png"; 
  std::string open_file = "gnome-terminal -x sh -c 'eog " + file + "'";
  
  open_file_chars = file.c_str();
  system(open_file_chars);

}

//plots function using gnuplot
void plot(std::string file1){

  std::string command = "gnuplot -e \"set terminal pngcairo; set output \'output.png\'; set title \'test\'; set xlabel \'x\'; set ylabel \'y\'; set xzeroaxis; set yzeroaxis; plot \'" + file1 + "\' using 1:2 with lines\" -p";
  std::string file;
  std::string filepart1 = "output.png"; 
  const char* command_chars;
  const char* file_chars;
  
  command_chars = command.c_str();
  //system(command_chars);

  file  = "eog " + filepart1;
  file_chars = file.c_str();
  //system(file_chars);

}


//plots function using gnuplot
void plot(std::string file1, std::string file2){

  std::string command = "gnuplot -e \"set terminal pngcairo; set output \'output.png\'; set title \'test\'; set xlabel \'x\'; set ylabel \'y\'; set xzeroaxis; set yzeroaxis; plot \'" + file1 + "\' using 1:2, \'" + file2 + "\' using 1:2 with lines\" -p";
  std::string file;
  std::string filepart1 = "output.png"; 
  const char* command_chars;
  const char* file_chars;
 	
	command_chars = command.c_str();
  //system(command_chars);

  file  = "eog " + filepart1;
  file_chars = file.c_str();
  //system(file_chars);

}