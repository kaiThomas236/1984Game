#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//going to use a 2d array to make a grid, fill it w values, player has auto start point (0, 0), enemies and helpers have randomized spaces
//will make npc's move if i have time, else static, pc has three lives, if pc hits thought police - lose game, hits telescreen - lose 1 life
//if pc hits a prole - given the coordinates of 1 thought police on the grid

//reference page (get some more, research!) - http://www.cplusplus.com/forum/beginner/65037/
//https://www.youtube.com/watch?v=oLCDLinBIzg

//g++ -std=c++11 game.cpp -o game && game



int main()
{
  string player = "";
  int lives = 3;
  bool dead = false;
  srand (time(NULL));
  string map[10][10];
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      map[i][j] = {"NULL"};
      //cout << map[i][j] << " | ";
    }
    //cout << endl << "_____________________________________________________________________" << endl;
  }
  for (int numTP = 0; numTP < 3; numTP++)
  {
    int x = rand()%10;
    if (x == 0)
      x += 1;
    int y = rand()%10;
    if (map[x][y] == "NULL")
    {
      map[x][y] = "TP";
    }
    else if (map[x+1][y] == "NULL")
    {
      map[x+1][y] = "TP";
    }
    else if (map[x][y+1] == "NULL")
    {
      map[x][y+1] = "TP";
    }
    //cout << x << ", " << y << endl;
  }
  for (int numTS = 0; numTS < 8; numTS++)
  {
    int x = rand()%10;
    if (x == 0)
      x += 1;
    int y = rand()%10;
    if (map[x][y] == "NULL")
    {
      map[x][y] = "TS";
    }
    else if (map[x+1][y] == "NULL")
    {
      map[x+1][y] = "TS";
    }
    else if (map[x][y+1] == "NULL")
    {
      map[x][y+1] = "TS";
    }
    //cout << x << ", " << y << endl;
  }
  for (int numP = 0; numP < 5; numP++)
  {
    int x = rand()%10;
    if (x == 0)
      x += 1;
    int y = rand()%10;
    if (map[x][y] == "NULL")
    {
      map[x][y] = "P";
    }
    else if (map[x+1][y] == "NULL")
    {
      map[x+1][y] = "P";
    }
    else if (map[x][y+1] == "NULL")
    {
      map[x][y+1] = "P";
    }
    //cout << x << ", " << y << endl;
  }
  /*for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      //map[i][j] = {"NULL"};
      cout << map[i][j] << " | ";
    }
    cout << endl << "_____________________________________________________________________" << endl;
  }*/


   cout << "Hello! Would you like to start the game? Y or N: ";
   string start;
   cin >> start;
   if (start == "Y")
   {
     cout << "Would you like to play as Winston or Julia? W or J: ";
     string choice;
     cin >> choice;
     if (choice == "W")
     {
       player = choice;
     }

     else if(choice == "J")
     {
       player = choice;
     }
     //cout << "jkhva" << endl;
     cout << "Great! Your starting coordinates are (0, 0). The goal of the game is to get to the end, with coordinates (9, 9), without dying. If you hit a member of the Thought Police you will lose immediately, if you hit a telescreen you will lose one of your three lives, if you hit a prole they will reveal to you the location of one member of the Thought Police. Good Luck! If you have any questions ask Kai, he built me." << endl;
     int r = 0;
     int k = 0;

     string direction = "";
     //cout << alive << " " << lives << endl;
     while (!dead && lives != 0)
     {
       cout << "Your current coordinates are (" << r << ", " << k << ")." << endl;
       if (r == 0 && k == 0)
       {
         cout << "Would you like to move south or west? S or W: ";
         cin >> direction;
       }
       else if (r ==  0 && k == 9)
       {
         cout << "Would you like to move south or east? S or E: ";
         cin >> direction;
       }
       else if (r == 9 && k == 0)
       {
         cout << "Would you like to move north or west? N or W: ";
         cin >> direction;
       }
       else if (r == 9 && k == 9)
       {
         cout << "You win the game! Congratulations!" << endl << endl;
         map[9][9] = player;
         for (int i = 0; i < 10; i++)
         {
           for (int j = 0; j < 10; j++)
           {
             //map[i][j] = {"NULL"};
             cout << map[i][j] << " | ";
           }
           cout << endl << "_____________________________________________________________________" << endl;
         }
         break;

       }
       else if (r == 0)
       {
         cout << "Would you like to move east, south, or west? E, S, or W: ";
         cin >> direction;

       }
       else if (k == 0)
       {
         cout << "Would you like to move north, south, or west? N, S, or W: ";
         cin >> direction;

       }
       else if (k == 9)
       {
         cout << "Would you like to move east, south, or north? E, S, or N: ";
         cin >> direction;
       }
       else if (r == 9)
       {
         cout << "Would you like to move east, north, or west? E, N, or W: ";
         cin >> direction;
       }
       else
       {
         cout << "Would you like to move south, east, north, or west? S, E, N, or W: ";
         cin >> direction;
       }
       if (direction == "N")
       {
          r--;
          //map[r][k] = player;
       }
       else if (direction == "S")
       {
          r++;
          //map[r][k] = player;
       }
       else if (direction == "E")
       {
          k--;
          //map[r][k] = player;
       }
       else if (direction == "W")
       {
          k++;
          //map[r][k] = player;
       }
       if (map[r][k] == "TS")
       {
        lives--;
        cout << "You've lost a life because you ran into a telescreen. You now have " << lives << " lives remaining." << endl;
       }
       else if (map[r][k] == "P")
       {
        //cout << r << ", " << k << endl;
        for (int i = r; i < 10; i++)
        {
          for (int j = k; j < 10; j++)
          {
            if (map[i][j] == "TP")
            {
              //cout << i << ", " << j << endl;
              cout << "You have run into a prole and they have given you the coordinates of one member of the thought police, at (" << i << ", " << j << "). I would reccommend avoiding this location." << endl;
              i = 10;
              j = 10;
            }

           }

          }
         }
      else if (map[r][k] == "TP")
      {
        dead = true;
        cout << "You have died because you ran into a member of the thought police." << endl << "Goodbye!" << endl << endl;
        map[r][k] = player;
        for (int i = 0; i < 10; i++)
        {
          for (int j = 0; j < 10; j++)
          {
            //map[i][j] = {"NULL"};
            cout << map[i][j] << " | ";
          }
          cout << endl << "_____________________________________________________________________" << endl;
        }
        break;
      }
      if (lives == 0)
      {
        dead = true;
        cout << "You have died because you lost all of your lives." << endl << "Goodbye!" << endl << endl;
        map[r][k] = player;
        for (int i = 0; i < 10; i++)
        {
          for (int j = 0; j < 10; j++)
          {
            //map[i][j] = {"NULL"};
            cout << map[i][j] << " | ";
          }
          cout << endl << "_____________________________________________________________________" << endl;
        }
        break;
      }
     }
   }
   else if (start == "N")
   {
     cout << "Goodbye!" << endl;
   }





 }
