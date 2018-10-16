#include "bake.h"

void storedef(int i, char line){

	//SHIIIIIIIT THIS AINT GONNA WORK.... fuck.. need to find a different way to do this

	//"i" will be the position of the = sign. "Line" should be the definition line
	char *sub = new char[i]; 
	char *def = new char[sizeof line - i]; //let me know if this will give me the length of the definition string 	

	int j = 0;
	while(line[j] != '\0') {
		//Substitution string
		if (j < i) {
			sub[j] = line[j];  
			}
		if (j = i) {

		}	
		if (j > i) {
			def[j-i-1] = line[j];
		}
	}

}

variable_sub(FILE *fpNoHash, FILE *fpNoVar){
	//We want to receive a fp and then return a modified fp 

	//This is what I think we should do:
	//Search through the whole file first
	//Find the 1st "=" in every line
	//If no "=" then ignore line
	//If  "=" store, in two arrays, what came before and after the = sign (I DONT THINK THIS WILL WORK -- LET ME KNOW IF YOUU THINK OF SOMETHING)
	//Then, go though, and when you find $(something that came before) then change it to "something that came after"
	char temp[BUFSIZE];
	fgets(temp, sizeof BUFSIZE, fp);
	
	//Search for 1st = sign
	int i = 0;
	while(temp[i] != '\0' && temp[i] != '='){
		i++
	}
	//Store what is before and after = sign
	if(temp[i] == '='){
	storedef(i, temp);
	}
}