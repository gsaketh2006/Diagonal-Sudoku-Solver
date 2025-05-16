#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int a[9][9]; 
int suitable(int row, int col, int num) 
{
    for (int i = 0; i < 9; i++) 
    {
        if (a[row][i] == num || a[i][col] == num) 
        {
            return 0;
        }
    }
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (a[r + i][c + j] == num) 
            {
                return 0;
            }
        }
    }
    if (row == col) 
    { 
        for (int i = 0; i < 9; i++) 
        {
            if (a[i][i] == num) 
            {
                return 0;
            }
        }
    }
    if (row + col == 8) 
    { 
        for (int i = 0; i < 9; i++) 
        {
            if (a[i][8 - i] == num) 
            {
                return 0;
            }
        }
    }
    return 1;
}
int solve() 
{
    int row, col;
    int found = 0;
    for (row = 0; row < 9; row++) 
    {
        for (col = 0; col < 9; col++) 
        {
            if (a[row][col] == 0) 
            {
                found = 1;
                break;
            }
        }
        if (found == 1) 
        {
            break;
        }
    }
    if (found == 0) 
    {
        return 1;
    }
    for (int num = 1; num <= 9; num++) 
    {
        if (suitable(row, col, num)) 
        {
            a[row][col] = num;
            if (solve()) 
            {
                return 1;
            }
            a[row][col] = 0; 
        }
    }
    return 0; 
}
int main() 
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Sudoku Solver");
    cout << "Enter the values in the Sudoku puzzle (0 for every empty cell): " << endl;
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> a[i][j];
        }
    }
    if (solve()) 
    {
        cout << "The Sudoku puzzle is solved!" << endl;
    } 
    else 
    {
        cout << "No solution" << endl;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        for (int i = 0; i <= 9; i++) 
        {
            sf::Vertex line1[] = { sf::Vertex(sf::Vector2f(0, i * 66)),
                                   sf::Vertex(sf::Vector2f(594, i * 66)) };
            
            sf::Vertex line2[] = { sf::Vertex(sf::Vector2f(i * 66, 0)),
                                   sf::Vertex(sf::Vector2f(i * 66, 594)) };

            if (i % 3 == 0) 
            {
                line1[0].color = sf::Color::Black;
                line2[0].color = sf::Color::Black;
            } 
            else 
            {
                line1[0].color = sf::Color(200, 200, 200);  
                line2[0].color = sf::Color(200, 200, 200);
            }

            window.draw(line1, 2, sf::Lines);
            window.draw(line2, 2, sf::Lines);
        }
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) 
        {
            cout << "Error loading font!" << endl;
            exit(1);
        }
        sf::Text text("", font, 24);
        text.setFillColor(sf::Color::Black);
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                if (a[i][j] != 0) 
                {
                    text.setString(std::to_string(a[i][j]));
                    float xPos = j * 66 + (66 - text.getLocalBounds().width) / 2;
                    float yPos = i * 66 + (66 - text.getLocalBounds().height) / 2;
                    text.setPosition(xPos, yPos);
                    window.draw(text);
                }
            }
        }
        window.display();
    }
    return 0;
}
