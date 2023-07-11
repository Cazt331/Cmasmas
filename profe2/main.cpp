#include <windows.h>

using namespace std;

typedef struct Alumno STUDENT;

struct Alumno {
     char nombre[50];
     unsigned long boleta;
};

void clrscr( )
{
    HANDLE hConsole;


   COORD coordScreen = { 0, 0 };    // home for the cursor
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Get the number of character cells in the current buffer.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // Fill the entire screen with blanks.

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write
                                    coordScreen,     // Coordinates of first cell
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }


   // Get the current text attribute.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   // Set the buffer's attributes accordingly.

   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute
                                    coordScreen,      // Coordinates of first cell
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}

void gotoxy(int x,int y){
  HANDLE hConsole;
  COORD cursorLoc;
  std::cout.flush();
  cursorLoc.X = x;
  cursorLoc.Y = y;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole, cursorLoc);
}



void leer(STUDENT *s){
    cout<<"Nombre del Estudiante:";
    cin.getline(s->nombre,50,'\n');
    cout<<"Boleta:";
    cin>>s->boleta;
    cin.ignore(255,'\n');
}
void ver(STUDENT s){
    cout<<"Nombre del Estudiante:"<<s.nombre<<endl;
    cout<<"Boleta:"<<s.boleta<<endl;
}

int main()
{
   STUDENT grupo[5];


   for(int i=0;i<5;i++) {
       clrscr();
       leer(&grupo[i]);
   }
   for(int i=0;i<5;i++)
       ver(grupo[i]);

   /*
  strcpy(a.nombre,"Juanito Perez");
  a.boleta=30000;

  cout<<"Nombre del Alumno:"<<a.nombre<<endl;
  cout<<"Boleta:"<<a.boleta<<endl;
  */
  return 0;
}
