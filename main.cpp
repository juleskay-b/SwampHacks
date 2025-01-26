#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>
#include "pet.h"
#include "player.h"
#include "math.h"
#include "Sprites.h"
#include "authentification.h"

using namespace std;

//set text stuff, fun :)
void setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

//tells the player when the pet was created, aka when the game was started - eventually will reset every time the pet dies
void drawDOB(sf::RenderWindow& window, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
    //not done yet, needs to be formatted and drawn
    sf::Text dobTitle;
    dobTitle.setFont(titleFont);
    dobTitle.setString(pet.getName() + " was born on " + player.getDate());
}

void drawInput(sf::RenderWindow& window, sf::Text& userInput, string& userName, float width, float height, sf::Font& font) {
    userInput.setFont(font);
    userInput.setCharacterSize(36);
    userInput.setFillColor(sf::Color::White);

    setText(userInput, (width / 2), (height / 2) - 45);
    window.clear();
    window.draw(userInput);
    window.display();
}

void drawUserAnswer(sf::RenderWindow& window, sf::Text& userInput, sf::Font& bodyFont, int& width, int& height) {
    userInput.setFont(bodyFont);
    userInput.setCharacterSize(20);
    userInput.setFillColor(sf::Color::White);

    setText(userInput, (width/2), height-100);
    window.clear();
    window.draw(userInput);
    window.display();
    }

int statsWindow(sf::RenderWindow& window, Sprites& textures, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
    sf::RectangleShape titleBox(sf::Vector2f(300,340));
    titleBox.setPosition(150, 20);
    titleBox.setFillColor(sf::Color::Blue);

    sf::Text title1;
    title1.setFont(titleFont);
    title1.setString(player.getName() + "'s Stats");
    title1.setCharacterSize(36);
    setText(title1,(width/2),64);

    sf::Text qr;
    qr.setFont(bodyFont);
    qr.setString("Questions answered: " + to_string(player.getQR()));
    qr.setCharacterSize(22);
    setText(qr, (width/2), 110);

    sf::Text qw;
    qw.setFont(bodyFont);
    qw.setString("Questions missed: " + to_string(player.getQW()));
    qw.setCharacterSize(22);
    setText(qw, (width/2), 140);

    sf::Text points;
    points.setFont(bodyFont);
    points.setString("Total points earned: " + to_string(player.getTotalPoints()));
    points.setCharacterSize(22);
    setText(points, (width/2), 170);

    sf::Text title2;
    title2.setFont(titleFont);
    title2.setString(pet.getName() + "'s Stats");
    title2.setCharacterSize(36);
    setText(title2, (width/2), (height/2));

    sf::Text health;
    health.setFont(bodyFont);
    health.setString(pet.getName() + "'s current health: " + to_string(pet.getHealth()));
    health.setCharacterSize(22);
    setText(health, (width/2), (height/2)+46);

    sf::Text dob;
    dob.setFont(bodyFont);
    dob.setString(pet.getName() + " was born on " + player.getDate());
    dob.setCharacterSize(22);
    setText(dob, (width/2), (height/2)+76);


    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }
        }

        window.clear();
        window.draw(titleBox);
        window.draw(title1);
        window.draw(qr);
        window.draw(qw);
        window.draw(points);
        window.draw(title2);
        window.draw(health);
        window.draw(dob);
        window.display();
    }

}

int startWindow(sf::RenderWindow& window, Sprites& textures, sf::Font& titleFont, sf::Font& bodyFont, int& width, int& height, player& player, Pet& pet) {
    sf::Sprite bg;
    bg.setTexture(textures.getBackgrounds().at(0));

    sf::Text title;
    title.setFont(titleFont);
    title.setString("- Mathfriend -");
    title.setCharacterSize(48);
    setText(title, (width/2), 64);

    sf::Text welcomeMessage;
    welcomeMessage.setFont(bodyFont);
    welcomeMessage.setString("Name your new pet:");
    welcomeMessage.setCharacterSize(30);
    setText(welcomeMessage,width/2, 120);

    string input;

    sf::Text petName;

    drawInput(window, petName, input, width, height, bodyFont);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (input.length() > 0) {
                        pet.rename(input);
                        window.clear();
                        return 1;
                    }
                }else if (event.key.code == sf::Keyboard::Backspace) {
                    if (input.length() > 0) {
                        input.pop_back();
                    }
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if ((isalpha(event.text.unicode) || isspace(event.text.unicode)) && input.size() < 16) {
                    input += static_cast<char>(event.text.unicode);
                }
            }
        }

        petName.setString(input + "|");
        setText(petName, width / 2, 216);

        window.clear();
        window.draw(bg);
        window.draw(welcomeMessage);
        window.draw(title);
        window.draw(petName);
        window.display();
    }
}

int gameWindow(sf::RenderWindow& window, sf::Font titleFont, sf::Font& bodyFont, Sprites& textures, int& width, int& height, player& player, Pet& pet) {
    int sidebar_left = 676;
    int sidebar_right = 740;
    int sidebar_top = 64;

    int stats_width = width * .75;
    int stats_height = height * .75;

    sf::Sprite background;
    background.setTexture(textures.getBackgrounds().at(1));

    sf::Text title;
    title.setFont(titleFont);
    title.setString("- Mathfriend -");
    title.setCharacterSize(48);
    setText(title, (width/2), 64);

    sf::Text line1;
    line1.setFont(bodyFont);
    line1.setString("Earn points care to for " + pet.getName() + ".\n"
                                                      "Solve problems to earn points.");
    line1.setCharacterSize(24);
    setText(line1, (width/2), 124);

    sf::Sprite petSprite;
    petSprite.setTexture(textures.getPetTextures().at(0));
    petSprite.setPosition(200,200);
    petSprite.setScale(.4,.4);

    sf::Sprite statsButton;
    statsButton.setTexture(textures.getButtons().at(0));
    statsButton.setPosition(sidebar_left,sidebar_top);
    statsButton.setScale(2,2);

    sf::Sprite easyButton;
    easyButton.setTexture(textures.getButtons().at(1));
    easyButton.setPosition(sidebar_left, sidebar_top+124);
    easyButton.setScale(2,2);

    sf::Sprite medButton;
    medButton.setTexture(textures.getButtons().at(2));
    medButton.setPosition(sidebar_left,sidebar_top+248);
    medButton.setScale(2,2);

    sf::Sprite hardButton;
    hardButton.setTexture(textures.getButtons().at(3));
    hardButton.setPosition(sidebar_left,sidebar_top+372);
    hardButton.setScale(2,2);

    sf::Text questionText;
    questionText.setFont(bodyFont);
    questionText.setString("Choose question difficulty:");
    setText(questionText, (width/2), height-125);

    sf::Text userInput;

    string answer;

    bool questionOpen = false;
    bool lockClick = false;

    Math myMath;

    string mode = "default";

    int hourCounter = 0;
    int a;
    int b;
    int choice;
    int points;

    player.getTime().resetTime();

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.clear();
                window.close();
                return 0;
            }

            if (!questionOpen){
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left && lockClick != true) {
                        lockClick = true;
                    }
                    if (event.mouseButton.button == sf::Mouse::Right && lockClick!= true) {
                        lockClick = true;
                    }
                }

                if (event.type == sf::Event::MouseButtonReleased) {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    //Sidebar buttons
                    if (pos.x < sidebar_right && pos.x > sidebar_left) {
                        if (pos.y > sidebar_top && pos.y < sidebar_top+64) {
                            cout << "Stats" << endl;
                            sf::RenderWindow smallWindow(sf::VideoMode(stats_width, stats_height), "Mathfriend");
                            statsWindow(smallWindow, textures, titleFont, bodyFont, stats_width, stats_height, player, pet);
                            //Open stats menu
                        }
                        if (pos.y > sidebar_top + 124 && pos.y < sidebar_top+188) {
                            questionOpen = true;
                            mode = "easy";
                            points = 3;

                            choice = rand() % 3;
                            a = rand() % 100;
                            b = rand() % 100;

                            switch (choice) {
                                case 0:
                                    questionText.setString(to_string(a) + " + " + to_string(b) + " = ?");
                                break;
                                case 1:
                                    questionText.setString(to_string(a) + " - " + to_string(b) + " = ?");
                                break;
                                case 2:
                                    questionText.setString(to_string(a) + " x " + to_string(b) + " = ?");
                                break;
                            }
                        }
                        if (pos.y > sidebar_top + 248 & pos.y < sidebar_top + 312) {
                            mode = "medium";
                            cout << "Medium" << endl;
                            //Give a medium question - division, multiplication (large) - earn 6 points
                        }
                        if (pos.y > sidebar_top + 372 & pos.y < sidebar_top + 436) {
                            mode = "hard";
                            cout << "Hard" << endl;
                            //Give a hard question - area of circle, volume of sphere, etc
                        }
                    }
                }

                if (event.type == sf::Event::KeyPressed && questionOpen) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        // Process the answer
                        if ((choice == 0 && stoi(answer) == a + b) ||
                                (choice == 1 && stoi(answer) == a - b) ||
                                (choice == 2 && stoi(answer) == a * b)) {
                                player.answerQuestion(points);
                                questionOpen = false;
                                questionText.setString("Correct");
                                } else {
                                    points--; // Deduct points for wrong answers
                                    questionText.setString("Try again");
                                }
                            answer.clear();
                        } else if (event.key.code == sf::Keyboard::Backspace && !answer.empty()) {
                            answer.pop_back();
                        }
                    }
                    if (event.type == sf::Event::TextEntered && questionOpen) {
                        if (isdigit(event.text.unicode) && answer.size() < 16) {
                            answer += static_cast<char>(event.text.unicode);
                            userInput.setString(answer + "|");
                        }
                    }
                }

                //Should be counting hours - however, due to time and lacking ability, just counting seconds since the program starts running
                if (player.getTime().getTotalSeconds() > hourCounter) {
                    pet.dec();
                    hourCounter++;
                }

                //Updates the Pet Sprite to reflect the pet's condition/health level
                if (pet.getHealth() > 66) {
                    petSprite.setTexture(textures.getPetTextures().at(0));
                } else if (pet.getHealth() > 33) {
                    petSprite.setTexture(textures.getPetTextures().at(1));
                } else if (pet.getHealth() > 0) {
                    petSprite.setTexture(textures.getPetTextures().at(2));
                } else if (pet.getHealth() == 0) {
                    petSprite.setTexture(textures.getPetTextures().at(4));
                    //Game over
                }

                if (questionOpen) {
                    drawUserAnswer(window, userInput, bodyFont, width, height);
                    userInput.setString(answer + "|");
                    setText(userInput, width / 2, 216);
                }

                window.clear();
                window.draw(background);
                window.draw(title);
                window.draw(line1);
                window.draw(petSprite);
                window.draw(statsButton);
                window.draw(easyButton);
                window.draw(medButton);
                window.draw(hardButton);
                window.draw(questionText);

                if (questionOpen) {
                    setText(userInput, width / 2, height - 125);
                    window.draw(userInput);
                }

                window.display();
            }
        }
    }

int main() {
    Sprites textures;
    textures.loadButtons();
    textures.loadPetTextures();
    textures.loadBackgrounds();

    player newPlayer;
    newPlayer.printStats();

    int width = 800;
    int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Mathfriend");

    sf::Font titleFont;
    titleFont.loadFromFile("files/JdLed5Regular-oRdA.ttf");

    sf::Font bodyFont;
    bodyFont.loadFromFile("files/SummerPixel22Regular-jE0W7.ttf");

    int gameStart = startWindow(window, textures, titleFont, bodyFont, width, height, newPlayer, newPlayer.getPet());

    if (gameStart == 1) {
        gameWindow(window, titleFont, bodyFont, textures, width, height, newPlayer, newPlayer.getPet());
    }

    return 0;
}