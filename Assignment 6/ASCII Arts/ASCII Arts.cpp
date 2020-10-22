//Written By Eddy Zhou
#include <iostream>
#include <cstdlib>
#include <fstream>

int main()
{
    std::string filename;

    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream fin(filename.c_str());
    if (!fin) 
    {
        std::cout << "File not found.\n";
        return EXIT_FAILURE;
    }
   
    const int MAX_HEIGHT = 200, MAX_WIDTH = 79;
    int rowNumber = 0, columnNumber = 0, heightToPrint = 0;
    char character, canvas[MAX_HEIGHT][MAX_WIDTH];
    fin >> heightToPrint;

    for (int row = 0; row < heightToPrint; row++) 
    {
        for (int column = 0; column < MAX_WIDTH; column++) 
        {
            canvas[row][column] = ' ';
        }
    }

    while (fin >> rowNumber >> columnNumber >> character) 
    {
        canvas[rowNumber][columnNumber] = character;
    }

    for (int row = 0; row < heightToPrint; row++) 
    {
        for (int column = 0; column < MAX_WIDTH; column++) 
        {
            std::cout << canvas[row][column];
        }
        std::cout << std::endl;
    }
}
/*
Sample Output 1:...............................................

Enter filename: homer_mapped.txt
                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'

Sample Output 2:...............................................

Enter filename: mickey_mapped.txt
                            _____
                        .d88888888bo.
                      .d8888888888888b.
                      8888888888888888b
                      888888888888888888
                      888888888888888888
                       Y8888888888888888
                 ,od888888888888888888P
              .'`Y8P'```'Y8888888888P'
            .'_   `  _     'Y88888888b
           /  _`    _ `      Y88888888b   ____
        _  | /  \  /  \      8888888888.d888888b.
       d8b | | /|  | /|      8888888888d8888888888b
      8888_\ \_|/  \_|/      d888888888888888888888b
      .Y8P  `'-.            d88888888888888888888888
     /          `          `      `Y8888888888888888
     |                        __    888888888888888P
      \                       / `   dPY8888888888P'
       '._                  .'     .'  `Y888888P`
          `"'-.,__    ___.-'    .-'
         jgs  `-._````  __..--'`

Sample Output 3:...................................................

Enter filename: st_basils_mapped.txt
                            .
                            T
                           ( )
                          <===>
                           F|J
                           ===
                          J|||F
                          F|||J
                         /\/ \/\
                         F+++++J
                        J{}{|}{}F         .
                     .  F{}{|}{}J         T
          .          T J{}{}|{}{}F        ;;
          T         /|\F/\/\|/\/\J  .   ,;;;;.
         /:\      .'/|\\:=========F T ./;;;;;;\
       ./:/:/.   ///|||\\\"""""""" /x\T\;;;;;;/
      //:/:/:/\  \\\\|////..[ ]...xXXXx.|====|
      \:/:/:/:T7 :.:.:.:.:||[ ]|/xXXXXXx\|||||
      ::.:.:.:A. `;:;:;:;'=== ==\XXXXXXX/=====.
      `;""::/xxx\.|,|,|,| ( ) ( )| | | |.=..=.|
       :. :`\xxx/(_)(_)(_) _   _ | | | |'-''-'|
       :T-'-.:"":|"""""""|/ \ / \|=====|======|
       .A."""||_|| ,. .. || | | |/\/\/\/ | | ||
   :;:////\:::.'.| || || ||-| |-|/\/\/\+|+| | |
  ;:;;\////::::,='======='=============/\/\=====.
 :;:::;""":::::;:|__..,__|============/||\|\====|
 :::::;|=:::;:;::|,;:::::          |========|   |
 ::l42::::::(}:::::;::::::_________|========|___|__

*/

