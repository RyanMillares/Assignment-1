#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
  double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164; //memorized haha
  double a,b,c; //for the weird gaussian formula thing
  int d;
  double sum = 0;
  double numLines = 0;
  double mean;
  double variance;
  double deviation;
  // initializing all as 0 so i can increment
  double totalTA = 0;
  double totalTC = 0;
  double totalTG = 0;
  double totalTT = 0;
  double totalGA = 0;
  double totalGC = 0;
  double totalGG = 0;
  double totalGT = 0;
  double totalCA = 0;
  double totalCC = 0;
  double totalCG = 0;
  double totalCT = 0;
  double totalAA = 0;
  double totalAC = 0;
  double totalAG = 0;
  double totalAT = 0;
  double totalA = 0;
  double totalC = 0;
  double totalT = 0;
  double totalG = 0;
  char first,second,check; //will store

  bool fileCheck = true;
  bool moreFiles = true;
  string currentLine;
  int odds = 0;
  string file;
  double prob;
  double total;


/**  while(fileCheck){
    if(argv > 1)
  }
  **/
  if(argc > 1){
    file = argv[1];
  } //if the command line argument is present, store as string
  do{
      if(argc > 1){



        ifstream inFile(file); //open istream with specified file, either command line or later as input
        ofstream outFile;
        outFile.open("RyanMillares.txt");

        //analysis loop
        while(getline(inFile, currentLine)){ // reads in current line of input stream until no more lines,
          if(currentLine.length()%2 != 0){
            int counter = 0;
            for(char& c : currentLine){
              switch(toupper(c)){
                case 'A':
                  totalA++;
                break;

                case 'C':
                  totalC++;
                break;

                case 'G':
                  totalG++;
                break;

                case 'T':
                  totalT++;
                break;
              }
              counter++;
              if(counter%2 == 0){ //if on an even number char, read in both the first and second chars to get the brigram
                second = toupper(c);
                if(first == 'A' && second == 'A'){
                  totalAA++;
                } else if(first == 'A' && second == 'C'){
                  totalAC++;
                } else if(first == 'A' && second == 'G'){
                  totalAG++;
                } else if(first == 'A' && second == 'T'){
                  totalAT++;
                } else if(first == 'C' && second == 'A'){
                  totalCA++;
                } else if(first == 'C' && second == 'C'){
                  totalCC++;
                } else if(first == 'C' && second == 'G'){
                  totalCG++;
                } else if(first == 'C' && second == 'T'){
                  totalCT++;
                } else if(first == 'G' && second == 'A'){
                  totalGA++;
                } else if(first == 'G' && second == 'C'){
                  totalGC++;
                } else if(first == 'G' && second == 'G'){
                  totalGG++;
                } else if(first == 'G' && second == 'T'){
                  totalGT++;
                } else if(first == 'T' && second == 'A'){
                  totalTA++;
                } else if(first == 'T' && second == 'C'){
                  totalTC++;
                } else if(first == 'T' && second == 'G'){
                  totalTG++;
                } else if(first == 'T' && second == 'T'){
                  totalTT++;
                }

              }
              else{ //otherwise (on an odd char) store the current char as "first"
                first = toupper(c); //stores first
              }


          }
          sum += currentLine.length() - 1; //weird bug with the line lengths where it was adding 1 to each length

          numLines++;

        }

          else{

            odds++; //disregards a line if it is an odd number
          }

        }

        //write loop
        //Calculation part

        mean = sum/numLines;
        total = sum;
        outFile << "Ryan Millares\nID: 2328529\nCPSC 350-03\n14 September 2019\n" << endl;
        outFile << odds << " lines omitted due to odd number of characters" << endl;
        outFile << numLines << " lines read and analyzed." << endl;
        outFile << "Nucleic Acid Probabilities: \nA: " << totalA/sum << "; C: " << totalC/sum << "; G: " << totalG/sum << "; T: " << totalT/sum << endl;
        outFile << "\nBigram Probabilities: " << endl;
        outFile << "AA: " << totalAA/(sum/2) << "; AC: " << totalAC/(sum/2) << "; AG: " << totalAG/(sum/2) << "; AT: " << totalAT/(sum/2) << endl;
        outFile << "CA: " << totalCA/(sum/2) << "; CC: " << totalCC/(sum/2) << "; CG: " << totalCG/(sum/2) << "; CT: " << totalCT/(sum/2) << endl;
        outFile << "GA: " << totalGA/(sum/2) << "; GC: " << totalGC/(sum/2) << "; GG: " << totalGG/(sum/2) << "; AT: " << totalGT/(sum/2) << endl;
        outFile << "TA: " << totalTA/(sum/2) << "; TC: " << totalTC/(sum/2) << "; TG: " << totalTG/(sum/2) << "; TT: " << totalTT/(sum/2) << endl;
        outFile << "Sum: " << sum << endl;
        outFile << "Average length: " << mean << endl;
        inFile.close();
        ifstream inFile2(file); //reopens file to restart from the beginning

        while(getline(inFile2, currentLine)){ //rereads all the line lengths in order to calculate variance and deviation
          sum = 0;
          if(currentLine.length()%2 == 0){
            for(char& e : currentLine){
              sum++;
            }
            sum += pow(sum - mean, 2);
          }
        }
        variance = sum/numLines;

        deviation = sqrt(variance);
        outFile << "Variance: " << variance << endl;
        outFile << "Standard Deviation: " << deviation << endl;
        //insane 1000 line time
        totalA = totalA/total;
        totalC = totalC/total + totalA;
        totalG = totalG/total + totalC;
        totalT = totalT/total + totalG;

        outFile << "\n\n\n1000 insane DNA Lines:" << endl;
        for(int i = 0; i < 1000; ++i){

          a = ((double) rand()/(RAND_MAX));
          b = ((double) rand()/(RAND_MAX));
          c = sqrt(-2*log(a))*cos(2*pi*b);
          d = deviation*c + mean;
          for(int j = 0; j < d; ++j){
            prob = ((double) rand()/(RAND_MAX));
            if(prob < totalA){
              outFile << "A";
            } else if((prob > totalA) && (prob < totalC)){
              outFile << "C";
            } else if((prob > totalC) && (prob < totalG)){
              outFile << "G";
            } else if((prob > totalG) && (prob < totalT)){
              outFile << "T";
            }
          }

          outFile << endl;
        }



        outFile.close();
        cout << "Do you want to try another dna file? Enter 'y' for yes, and any other input for no." << endl;
        cin >> check;
        if(tolower(check) == 'y'){
          sum = 0;
          numLines = 0;

          totalTA = 0;
          totalTC = 0;
          totalTG = 0;
          totalTT = 0;
          totalGA = 0;
          totalGC = 0;
          totalGG = 0;
          totalGT = 0;
          totalCA = 0;
          totalCC = 0;
          totalCG = 0;
          totalCT = 0;
          totalAA = 0;
          totalAC = 0;
          totalAG = 0;
          totalAT = 0;
          totalA = 0;
          totalC = 0;
          totalT = 0;
          totalG = 0;
          cout << "Please input the name of the new text file: ";
          cin >> file;

        }
        else{
            moreFiles = false;
            cout << "Have a great day!" << endl;
        }

      }

      else{
        cout << "Please provide a text file to read from in command line next time." << endl;
        break;

      }
    } while(moreFiles);
  return 0;
}
