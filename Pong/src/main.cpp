#include <raylib.h>
#include <raymath.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

struct Ball
{
    Vector2 position = {WIDTH / 2, HEIGHT / 2};
    int SpeedX = 250;
    int SpeedY = 300;
    float radius = 5.0;

    void Draw()
    {
        DrawCircleV(position, radius, WHITE);
    }
};

struct Paddle
{
    float x, y;
    Vector2 size = {10, 100};
    int speed;
    
    Rectangle GetRect()
    {
        return (Rectangle) {x, y, size.x, size.y};
    }

    void Draw()
    {
        DrawRectangleRec(this->GetRect(), WHITE);
    }
};

int main(void) 
{
    float leftPaddleX = 50;
    float leftPaddleY = HEIGHT / 2 - 50;
    float rightPaddleX = WIDTH - 50;
    float rightPaddleY = HEIGHT / 2 - 50;
    int leftPaddlePoints = 0;
    int rightPaddlePoints = 0;
    int frames = 0;
    int timer = 0;
    Ball ball;
    Paddle leftPaddle;
    Paddle rightPaddle;
    leftPaddle.speed = 500;
    rightPaddle.speed = 500;

    InitWindow(WIDTH, HEIGHT, "Game");
    SetWindowState(FLAG_VSYNC_HINT);
   
    while(!WindowShouldClose())
    {
        frames++;

        if(frames == 60)
        {
            frames = 0;
            timer++;
        }
        ball.position.x += ball.SpeedX * GetFrameTime();
        ball.position.y += ball.SpeedY * GetFrameTime();

        if(IsKeyDown(KEY_W))
            leftPaddleY -= leftPaddle.speed * GetFrameTime();

        if(IsKeyDown(KEY_S))
            leftPaddleY += leftPaddle.speed * GetFrameTime();

        if(IsKeyDown(KEY_UP))
            rightPaddleY -= rightPaddle.speed * GetFrameTime();

        if(IsKeyDown(KEY_DOWN))
            rightPaddleY += rightPaddle.speed * GetFrameTime();

        if(ball.position.y <= 0)
        {
            ball.position.y = 0;
            ball.SpeedY *= -1;
        }

        if(ball.position.y >= HEIGHT)
        {
            ball.position.y = HEIGHT;
            ball.SpeedY *= -1;
        }

        if(ball.position.x >= WIDTH)
        {
            ball.position.x = WIDTH / 2;
            leftPaddlePoints += 1;
        }

        if(ball.position.x <= 0)
        {
            ball.position.x = WIDTH / 2;
            rightPaddlePoints += 1;
        }

        leftPaddle.x = leftPaddleX;
        leftPaddle.y = leftPaddleY;
        rightPaddle.y = rightPaddleY;
        rightPaddle.x = rightPaddleX;

        if(CheckCollisionCircleRec(ball.position, ball.radius, (Rectangle) { rightPaddle.GetRect() }))
        {
            ball.SpeedX *= -1;
        }

        if(CheckCollisionCircleRec(ball.position, ball.radius, (Rectangle) { leftPaddle.GetRect() }))
        {
            ball.SpeedX *= -1;
        }
        const char* text = TextFormat("%d", timer);
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 50, 1);
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("%d", leftPaddlePoints), 50, 50, 20, leftPaddlePoints > rightPaddlePoints ? GREEN : WHITE);
            DrawText(TextFormat("%d", rightPaddlePoints), WIDTH - 50, 50, 20, rightPaddlePoints > leftPaddlePoints ? GREEN : WHITE);
            DrawText(TextFormat("%d", timer), WIDTH / 2 - text_size.x / 2, 50, 50, RED);
            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();
            DrawFPS(10, 10);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}