#include<iostream>
#include"Board.h"
#include"Player.h"
#include"Item.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

using namespace std;
using namespace sf;

int main() {

    cout << "     \t\t WELCOME TO ADVENTURE QUEST GAME \n";
    cout << " \t\t==================================\n\n";

    cout << " \t\t\t\t   Player 1 has given 100 points \n";
    cout << " \t\t\t\t Player 2 has given 100 points \n";
    cout << "###################     For to Complete Every level Each Player has given 50 more points \n\n";

    bool IsPlayerTurn = true;  // Initialize turn (Player 1 starts)
    int n = 0;
    int nu , total = 1;
    for (int i = 0; i <= 3; i++) {

        RenderWindow window(VideoMode(880, 600), "Adventure Quest");

        Board board(5 + n);
        window.setFramerateLimit(60);

        int lastIndex = board.getSize() - 1;
        Player player1(Color::Magenta, lastIndex, 0, true);
        Player player2(Color::Green, 0, lastIndex, false);

        player1.move(board.getpathR(0), board.getpathC(0));

        int LastIndex = board.getSize() * board.getSize() - 1;
        player2.setPath(LastIndex);
        player2.move(board.getpathR(LastIndex), board.getpathC(LastIndex));

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
                // Movement key for player 1 is A
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::A) {
                        if (IsPlayerTurn) {
                            player1.moveFor(board);
                            cout << "Player 1 moved to (" << player1.getRow() << ", " << player1.getCol() << ")" << endl;
                            IsPlayerTurn = false;  // Now it's Player 2's turn
                        }
                        else {
                            cout << "\t\t Other player's turn! Wait for your turn." << endl;
                        }
                    }

                    if (event.key.code == Keyboard::K) {
                        if (!IsPlayerTurn) {
                            /*cout << "Player 2 Key Pressed!" << endl;*/
                            player2.moveFor(board);
                            cout << "Player 2 moved to (" << player2.getRow() << ", " << player2.getCol() << ")" << endl;
                            IsPlayerTurn = true;  // Now it's Player 1's turn
                        }
                        else {
                            cout << "\t\t Other player's turn! Wait for your turn." << endl;
                        }
                    }
                }

                Item* p1Item = board.getItemAt(player1.getRow(), player1.getCol());
                if (p1Item) {
                    p1Item->interact(player1);
                    board.removeItemAt(player1.getRow(), player1.getCol());
                }

                Item* p2Item = board.getItemAt(player2.getRow(), player2.getCol());
                if (p2Item) {
                    p2Item->interact(player2);
                    board.removeItemAt(player2.getRow(), player2.getCol());
                }
            }

            // Clear window
            window.clear(Color::Black);

            // Draw everything 
            board.draw(window);
            int cellSize = board.getCellSize();
            float offsetX = board.getOffsetX();
            float offsetY = board.getOffsetY();

            player1.draw(window, cellSize, offsetX, offsetY);
            player2.draw(window, cellSize, offsetX, offsetY);

            // Display window
            window.display();

            int center = (board.getSize() * board.getSize()) / 2;
            int centerRow = board.getpathR(center);
            int centerCol = board.getpathC(center);

            if ((player1.getRow() == centerRow && player1.getCol() == centerCol) ||
                (player2.getRow() == centerRow && player2.getCol() == centerCol)) {
                cout << " Game Over! Player reached the red cell!" << endl;
                window.close();
            }
        }

        cout << "\t\t  That is a 4 level game \n\n";
        cout << " Do you want next level \n" <<
            " if yes then press 1 and if  no then press any number \n";
        cin >> nu;
            if (nu == 1) {
                cout << " Game restart player reach their initial point \n";
                n = n + 2;
                total++; // Avoid any mis understanding 
            }
            else if (nu != 1) {
                cout << " Game stopped after command by player \n";
                break;
            }
    }
    if (total == 3) {
        cout << " Congratulations for completing the game \n";
    }
    else {
        cout << " I hope you enjoy this game \n";
    }

    return 0;
}
