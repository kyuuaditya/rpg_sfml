// to run the compiler
// g++ -I"C:\SFML-2.6.2\include" -c main.cpp -o app.o
// g++ -I"C:\SFML-2.6.2\include" .\app.o -o app.exe -L"C:\SFML-2.6.2\lib" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows
#include <SFML/Graphics.hpp>

int main(){
    // ------------------ Initialization ------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // set the antialiasing level

    sf::RenderWindow window(sf::VideoMode(1920,1080),"RPG",sf::Style::Fullscreen,settings); // used to create the main window
    float color = 0.f;

    sf::CircleShape circle1(50.f); // draw a circle
    circle1.setFillColor(sf::Color::Magenta); // set the color of the shape
    circle1.setPosition(sf::Vector2f(100.f,100.f)); // set the position of the shape
    circle1.setOutlineThickness(5.f); // set the thickness of the outline
    circle1.setOutlineColor(sf::Color(0,120,120)); // set the color of the outline

    sf::RectangleShape rectangle1(sf::Vector2f(200,100)); // drawing a rectangle
    rectangle1.setFillColor(sf::Color(color,80,80)); // set the color of the shape
    rectangle1.setPosition(sf::Vector2f(400.f,200.f)); // set the position of the shape
    rectangle1.setOrigin(sf::Vector2f(100.f,50.f)); // set the origin of the shape within the shape
    rectangle1.rotate(90.f); // rotate the shape about the origin
    sf::RectangleShape rectangle2;
    rectangle2.setSize(sf::Vector2f(200,100));
    rectangle2.setFillColor(sf::Color(80,80,80));
    rectangle2.setPosition(sf::Vector2f(400.f,200.f));
    rectangle2.setOrigin(sf::Vector2f(100.f,50.f));
    // rectangle2.rotate(10.f);

    // to draw a circle.
    sf::CircleShape circle2(10.f,6);
    circle2.setFillColor(sf::Color::Yellow);
    circle2.setPosition(sf::Vector2f(100.f,100.f));

    // to draw a polygon(traingle) with 3 points
    sf::CircleShape triangle(50.f,3);
    triangle.setFillColor(sf::Color::Green);
    triangle.setPosition(sf::Vector2f(300.f,300.f));

    // to draw a conver shape with individual points
    // the points are connected in either clockwise or anticlockwise order.
    sf::ConvexShape convex(6);
    convex.setPoint(0,sf::Vector2f(100.f,300.f));
    convex.setPoint(1,sf::Vector2f(150.f,280.f));
    convex.setPoint(2,sf::Vector2f(200.f,320.f));
    convex.setPoint(3,sf::Vector2f(250.f,300.f));
    convex.setPoint(4,sf::Vector2f(250.f,400.f));
    convex.setPoint(5,sf::Vector2f(150.f,400.f));

    // to draw a line with a thickness
    sf::RectangleShape line1(sf::Vector2f(200.f,5.f));
    line1.setFillColor(sf::Color::White);
    line1.setPosition(sf::Vector2f(400.f,300.f));
    line1.rotate(10.f);

    // to draw a line from one point to another
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(0.f,0.f),sf::Color::Red),
        sf::Vertex(sf::Vector2f(800.f,600.f),sf::Color::Blue)
    };


    // ------------------ Initialization ------------------

    //main loop
    while(window.isOpen()){
        //checks for events every frame
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); // close the window
            }
        }

        // ---------------- Update ------------------
        color+=0.01f;
        int colora=int(color)%256;
        rectangle1.setFillColor(sf::Color(colora,80,80));
        // ---------------- Update ------------------

        // ---------------- Draw ------------------
        window.clear(sf::Color::Black); // clear the previous frame

        // drawing all the shapes
        window.draw(circle1); 
        window.draw(circle2);
        window.draw(rectangle2);
        window.draw(rectangle1);
        window.draw(triangle);
        window.draw(convex);
        window.draw(line1);
        window.draw(line,2,sf::Lines);

        window.display(); // display the current frame
        // ---------------- Draw -----------------
    }

    return 0;
}