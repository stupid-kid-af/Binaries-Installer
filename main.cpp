#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
using namespace std;


int main()
{
      string start="[Desktop Entry]";
      string ver="Version=";
      string name= "Name=";
      string Exec="Exec=";
      string isTerminal="Terminal= ";
      string Type="Type= ";
      string Categories="Categories= ";


      string input_ver;
      cout << "\033[1;31mEnter the version: \033[0m\n";
      cin >> input_ver;
      string final_ver= ver + input_ver;
//      cout<< final_ver;

      string input_name;
      cout << "\033[1;31mEnter your App Name: \033[0m\n";
      cin >> input_name;
      string final_name= name + input_name;
//      cout<< final_name;

      string input_exec;
      cout << "\033[1;31mEnter your App Exec: \033[0m\n";
      cin >> input_exec;
      string final_exec= Exec + input_exec;

      string input_isTerm;
      cout << "\033[1;31mIs Terminal? True/False: \033[0m\n";
      cin >> input_isTerm;
      string final_term= isTerminal + input_isTerm;

      string input_Type;
      cout << "\033[1;31mEnter Application type: \033[0m\n";
      cin >> input_Type;
      string final_type = Type + input_Type;

      string input_ctg;
      cout << "\033[1;31mEnter the app's category: \033[0m\n";
      cin >> input_ctg;
      string final_ctg = Categories + input_ctg + ";";

//      cout<< final_exec;
      string newline= "\n";
      string comp_file= start + newline+ final_ver +newline+ final_name + newline+ final_exec + newline + final_term + newline + final_type + newline + final_ctg + newline;
      cout<< comp_file;

      ofstream out("Test.desktop");
      out<< comp_file;
      system("sudo mv *.desktop $HOME/.local/share/applications/");

      string binaries_folder;
      cout << "\033[1;31mName the folder where the binaries (single executable or multiple files) are: \033[0m\n";
      cin >> binaries_folder;
      system(("sudo rm /usr/bin/" + binaries_folder).c_str());

      system(("sudo mv " + binaries_folder + " /usr/bin/").c_str());
      cout << "\033[1;31mInstalled!s\033[0m\n";
//      system("move_files.sh");
//      execl("/system/bin/sh","move_files.sh");
//      string final_desktop_string = start"/n" + final_ver "/n" + final_name "/n "+ final_exec "/n";
//      cout<< final_desktop_string;
//    cout << "Hello world!" << endl;


    return 0;
}
