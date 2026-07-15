#include"alibi.h"
#include"mystr.h"
#include"address.h"
#include"date.h"
#include"time.h"
#include"clue.h"
#include"game_obj.h"
#include"room.h"
#include"detective.h"
#include"suspect.h"
#include"investigation_case.h"
#include"raylib.h"
#include"raygui.h"
#include"log.h"

enum Screen { MAIN_MENU, INPUT_INFO, DETECTIVE_PROF,DET_PROF_VIEW,DIFFICULTY,EASY,MEDIUM,HARD,VIEW_SUSPECT_EASY, VIEW_SUSPECT_MED,VIEW_SUSPECT_HARD,INTEREZ1,INTEREZ2,INTEREZ3,SEARCH_ROOMS_EASY, SEARCH_ROOMS_MED,SEARCH_ROOMS_HARD, R1EZ, R2EZ, R3EZ,VIEW_EVIDENCE_EASY,VIEW_EVIDENCE_HARD,MAKING_ACCUSATION_EASY,MAKING_ACCUSATION_HARD,EZSUSP1,EZSUSP2,EZSUSP3,EASY_WIN,EASY_LOSE,VIEW_EVIDENCE_MED,MAKING_ACCUSATION_MED, MEDSUSP1, MEDSUSP2, MEDSUSP3, MEDSUSP4, MEDSUSP5, INTERMED1,INTERMED2,INTERMED3,INTERMED4,INTERMED5, R1MED,R2MED,R3MED,R4MED,R5MED,MED_WIN,MED_LOSE, HARDSUSP1,HARDSUSP2,HARDSUSP3,HARDSUSP4,HARDSUSP5,HARDSUSP6,HARDSUSP7,HARDSUSP8, INTERHARD1,INTERHARD2,INTERHARD3,INTERHARD4,INTERHARD5,INTERHARD6,INTERHARD7,INTERHARD8, R1HARD,R2HARD,R3HARD,R4HARD,R5HARD,R6HARD,R7HARD,HARD_WIN,HARD_LOSE,INSTRUCTIONS, EXIT };
Screen currentScreen = MAIN_MENU;

char temp_name[30] = { '\0' };
char temp_age[6] = { '\0' };
char gender = 'A';
char temp_yr[6] = { '\0' };
char temp_mon[3] = { '\0' };
char temp_d[3] = { '\0' };

bool name_edit = true;
bool age_edit = false;
bool day_edit = false;
bool month_edit = false;
bool year_edit = false;
bool statement_edit_ez1 = false;
bool time_edit_ez1 = false;
bool witness_edit_ez1 = false;
bool location_edit_ez1 = false;
bool statement_edit_ez2 = false;
bool time_edit_ez2 = false;
bool witness_edit_ez2 = false;
bool location_edit_ez2 = false;
bool statement_edit_ez3 = false;
bool time_edit_ez3 = false;
bool witness_edit_ez3 = false;
bool location_edit_ez3 = false;
bool btnobj1ezr1 = false;
bool btnobj1ezr2 = false;
bool btnobj1ezr3 = false;
bool btnobj1ezr1cl = false;
bool btnobj2ezr1cl = false;
bool btnobj3ezr1cl = false;

bool statement_edit_med1 = false;
bool time_edit_med1 = false;
bool witness_edit_med1 = false;
bool location_edit_med1 = false;
bool statement_edit_med2 = false;
bool time_edit_med2 = false;
bool witness_edit_med2 = false;
bool location_edit_med2 = false;
bool statement_edit_med3 = false;
bool time_edit_med3 = false;
bool witness_edit_med3 = false;
bool location_edit_med3 = false;
bool statement_edit_med4 = false;
bool time_edit_med4 = false;
bool witness_edit_med4 = false;
bool location_edit_med4 = false;
bool statement_edit_med5 = false;
bool time_edit_med5 = false;
bool witness_edit_med5 = false;
bool location_edit_med5 = false;

bool statement_edit_hard1 = false;
bool time_edit_hard1 = false;
bool witness_edit_hard1 = false;
bool location_edit_hard1 = false;
bool statement_edit_hard2 = false;
bool time_edit_hard2 = false;
bool witness_edit_hard2 = false;
bool location_edit_hard2 = false;
bool statement_edit_hard3 = false;
bool time_edit_hard3 = false;
bool witness_edit_hard3 = false;
bool location_edit_hard3 = false;
bool statement_edit_hard4 = false;
bool time_edit_hard4 = false;
bool witness_edit_hard4 = false;
bool location_edit_hard4 = false;
bool statement_edit_hard5 = false;
bool time_edit_hard5 = false;
bool witness_edit_hard5 = false;
bool location_edit_hard5 = false;
bool statement_edit_hard6 = false;
bool time_edit_hard6 = false;
bool witness_edit_hard6 = false;
bool location_edit_hard6 = false;
bool statement_edit_hard7 = false;
bool time_edit_hard7 = false;
bool witness_edit_hard7 = false;
bool location_edit_hard7 = false;
bool statement_edit_hard8 = false;
bool time_edit_hard8 = false;
bool witness_edit_hard8 = false;
bool location_edit_hard8 = false;

my_str temp_hr_ez1, temp_min_ez1, temp_secs_ez1;
my_str temp_hr_ez2, temp_min_ez2, temp_secs_ez2;
my_str temp_hr_ez3, temp_min_ez3, temp_secs_ez3;

my_str temp_hr_med1, temp_min_med1, temp_secs_med1;
my_str temp_hr_med2, temp_min_med2, temp_secs_med2;
my_str temp_hr_med3, temp_min_med3, temp_secs_med3;
my_str temp_hr_med4, temp_min_med4, temp_secs_med4;
my_str temp_hr_med5, temp_min_med5, temp_secs_med5;

my_str temp_hr_hard1, temp_min_hard1, temp_secs_hard1;
my_str temp_hr_hard2, temp_min_hard2, temp_secs_hard2;
my_str temp_hr_hard3, temp_min_hard3, temp_secs_hard3;
my_str temp_hr_hard4, temp_min_hard4, temp_secs_hard4;
my_str temp_hr_hard5, temp_min_hard5, temp_secs_hard5;
my_str temp_hr_hard6, temp_min_hard6, temp_secs_hard6;
my_str temp_hr_hard7, temp_min_hard7, temp_secs_hard7;
my_str temp_hr_hard8, temp_min_hard8, temp_secs_hard8;

alibi temp_alibi;
person person_prof;
detective detective_prof;

investigation ezobj,medium_obj,hard_obj;
void DrawInstructionsScreen() 
{
    int x = 50;
    int y = 40;
    int line_spacing = 20;

    Color cyan = { 100, 255, 255, 255 };
    Color subtleInfo = { 140, 180, 200, 255 };
    Color lightText = { 200, 240, 255, 255 };
    Color alertRed = { 255, 100, 100, 255 };
    Color aqua = { 0, 220, 220, 255 };

    DrawText("WELCOME, DETECTIVE!", x, y, 20, GOLD);
    y = y + (line_spacing * 2);

    DrawText("You've been assigned a murder case. Your goal is to investigate the scene, collect clues,", x, y, 17, lightText);
    y = y + line_spacing;

    DrawText("question suspects, and finally identify the killer.", x, y, 17, lightText);
    y = y + (line_spacing * 2);

    DrawText("HOW TO PLAY", x, y, 20, SKYBLUE);
    y = y + line_spacing;

    DrawText("1. Create Your Profile", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("   - Enter your name and age to begin your investigation career.", x, y, 15, subtleInfo);
    y = y + line_spacing;

    DrawText("2. Select a Difficulty Level", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("   - Easy", x, y, 15, subtleInfo);
    y = y + line_spacing;
    DrawText("   - Medium", x, y, 15, subtleInfo);
    y = y + line_spacing;
    DrawText("   - Hard", x, y, 15, subtleInfo);
    y = y + line_spacing;

    DrawText("3. Read the Case Summary", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("   - Get the background story, location, and key details of the crime.", x, y, 15, subtleInfo);
    y = y + line_spacing;

    DrawText("4. Begin the Investigation", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("   - View Suspects: Learn about their backgrounds and alibis.", x, y, 15, subtleInfo);
    y = y + line_spacing;
    DrawText("   - Search Rooms: Examine rooms and objects to find clues.", x, y, 15, subtleInfo);
    y = y + line_spacing;
    DrawText("   - Review Clues: Track the evidence you’ve collected.", x, y, 15, subtleInfo);
    y = y + line_spacing;
    DrawText("   - Make Accusation: When you're ready, name the killer.", x, y, 15, subtleInfo);
    y = y + (line_spacing * 2);

    DrawText("TIPS FOR SOLVING THE CASE", x, y, 20, SKYBLUE);
    y = y + line_spacing;
    DrawText("- Not all objects contain clues. Some are red herrings, choose wisely.", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("- Compare clues with alibis. Contradictions may reveal the liar.", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("- Clues may be misleading (especially in Medium and Hard modes).", x, y, 17, lightText);
    y = y + line_spacing;
    DrawText("- You only get one chance to accuse! Be confident in your logic.", x, y, 17, alertRed);
    y = y + (line_spacing * 2);
}

int main() 
{
    logger& log = logger::getInstance();
    log.initialize("game_log.txt");

    clue no_cl;
    dynamic_array<clue> no_clue(1, no_cl);
    InitWindow(800, 600, "Detective Investigation Simulator");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/house3.jpg");

    Texture2D txdet1 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/det1.png");
    Texture2D txdet2 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/det2.png");
    Texture2D txdet3 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/det3.png");
    Texture2D txdet4 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/det4.png");

    Texture2D txezsusp1 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/ezsusp11.png");
    Texture2D txezsusp2 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/ezsusp2.png");
    Texture2D txezsusp3 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/ezsusp3.png");

    Texture2D txez1study = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/studyez1.jpg");
    Texture2D txez1kitchen = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/kitchenez1.jpg");
    Texture2D txez1bedroom = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/bedroomez1.jpg");

    Texture2D txmedsusp1 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medsusp3.png");
    Texture2D txmedsusp2 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medsusp2.png");
    Texture2D txmedsusp3 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/ezsusp3.png");
    Texture2D txmedsusp4 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medsusp4.png");
    Texture2D txmedsusp5 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medsusp5.png");

    Texture2D txmedr1 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/studyez1.jpg");
    Texture2D txmedr2 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medr2.png");
    Texture2D txmedr3 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/bedroomez1.jpg");
    Texture2D txmedr4 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medr4.png");
    Texture2D txmedr5 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medr5.jpeg");

    Texture2D txhardsusp1 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp1.png");
    Texture2D txhardsusp2 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp2.png");
    Texture2D txhardsusp3 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp3.png");
    Texture2D txhardsusp4 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp4.png");
    Texture2D txhardsusp5 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp5.png");
    Texture2D txhardsusp6 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp6.png");
    Texture2D txhardsusp7 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/medsusp5.png");
    Texture2D txhardsusp8 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardsusp8.png");

    Texture2D txhardr1 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/studyez1.jpg");
    Texture2D txhardr2 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardr2.jpeg");
    Texture2D txhardr3 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardr3.jpeg");
    Texture2D txhardr4 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardr4.jpeg");
    Texture2D txhardr5 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/hardr5.jpeg");
    Texture2D txhardr6 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/bedroomez1.jpg");
    Texture2D txhardr7 = LoadTexture("C:/Users/PC/source/repos/oop final project/Pics/kitchenez1.jpg");

    Rectangle btnStart = { 300, 180, 220, 60 };
    Rectangle btnInstructions = { 300, 260, 220, 60 };
    Rectangle btnExit = { 300, 340, 220, 60 };
    Rectangle btn_back_instructions = { 620, 550, 150, 40 };
    Rectangle right_back_btn{ 60,550,150,40 };
    ofstream fout("easy_evidence.txt", ios::trunc);
    fout.close();
    ofstream f1out("med_evidence.txt", ios::trunc);
    f1out.close();
    ofstream f2out("hard_evidence.txt", ios::trunc);
    f1out.close();

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Rectangle src = { 0, 0, (float)texture.width, (float)texture.height };
        Rectangle dest = { 0, 0, 800, 600 };
        DrawTexturePro(texture, src, dest, { 0, 0 }, 0.0f, WHITE);

        if (currentScreen == MAIN_MENU)
        {
            DrawText("Detective Investigation Simulator", 170, 60, 30, WHITE);

            if (GuiButton(btnStart, "Start"))
            {
                log.write_action("User Started the game");
                currentScreen = INPUT_INFO;
            }
            if (GuiButton(btnInstructions, "Instructions"))
            {
                log.write_action("User read the instructions.");
                currentScreen = INSTRUCTIONS;
            }
            if (GuiButton(btnExit, "Exit"))
            {
                log.write_action("User exited the game");
                currentScreen = EXIT;
            }
        }

        else if (currentScreen == INPUT_INFO)
        {
            DrawRectangleRec({ 180, 60, 500, 500 }, Fade(Color{ 25, 25, 35, 255 }, 0.6f));
            DrawText("Create Your Profile", 200, 75, 20, YELLOW);

            Rectangle name_tb = { 270, 120, 260, 30 };
            Rectangle name_label = { 270, 105, 260, 20 };
            GuiTextBox(name_tb, temp_name, 30, name_edit);
            GuiLabel(name_label, "Name:");
            if (name_edit && GuiButton({ 540, 120, 60, 30 }, "Done"))
            {
                name_edit = false;
            }

            Rectangle age_tb{ 270, 180, 100, 30 };
            Rectangle age_label{ 270, 160, 260, 20 };
            GuiTextBox(age_tb, temp_age, 6, age_edit);
            GuiLabel(age_label, "Age:");
            if(!age_edit&& GuiButton({ 380, 180, 60, 30 }, "Edit"))
                age_edit=true;

            else if (age_edit && GuiButton({ 380, 180, 60, 30 }, "Done"))
            {
                age_edit = false;
            }

            Rectangle gender_label{ 270, 220, 260, 20 };
            Rectangle male_btn{ 270, 240, 80, 30 };
            Rectangle female_btn{ 360, 240, 80, 30 };
            GuiLabel(gender_label, "Gender:");
            if (GuiButton(male_btn, "Male"))
                gender = 'M';
            if (GuiButton(female_btn, "Female"))
                gender = 'F';

            if (gender == 'M')
                DrawText("Gender selected: Male", 270, 280, 10, GREEN);
            else if (gender == 'F')
                DrawText("Gender selected: Female", 270, 280, 10, GREEN);
            else
                DrawText("Gender not selected!", 270, 280, 10, RED);

            Rectangle date_label{ 270, 310, 260, 20 };
            Rectangle day_label{ 270, 330, 50, 20 };
            Rectangle day_input{ 270, 350, 50, 30 };
            Rectangle month_label{ 330, 330, 60, 20 };
            Rectangle month_input{ 330, 350, 50, 30 };
            Rectangle yr_label{ 390, 330, 60, 20 };
            Rectangle yr_input{ 390, 350, 80, 30 };

            GuiLabel(date_label, "Date of Birth:");

            GuiLabel(day_label, "Day");
            GuiTextBox(day_input, temp_d, 3, day_edit);
            if (!day_edit && GuiButton({ 270, 390, 50, 30 }, "Edit"))
            {
                day_edit = true;
                month_edit = false;
                year_edit = false;
            }

            else if (day_edit && GuiButton({ 270, 390, 50, 30 }, "Done"))
            {
                day_edit = false;
            }

            GuiLabel(month_label, "Month");
            GuiTextBox(month_input, temp_mon, 3, month_edit);
            if (!month_edit && GuiButton({ 330, 390, 50, 30 }, "Edit"))
            {
                month_edit = true;
                day_edit = false;
                year_edit = false;
            }

            else if (month_edit && GuiButton({ 330, 390, 50, 30 }, "Done"))
            {
                month_edit = false;
            }

            GuiLabel(yr_label, "Year");
            GuiTextBox(yr_input, temp_yr, 6, year_edit);
            if (!year_edit && GuiButton({ 390, 390, 80, 30 }, "Edit"))
            {
                year_edit = true;
                day_edit = false;
                month_edit = false;
            }

            else if (year_edit && GuiButton({ 390, 390, 80, 30 }, "Done"))
            {
                year_edit = false;
            }

            Rectangle btnconfirm{ 340, 450, 200, 40 };
            if (GuiButton(btnconfirm, "Confirm"))
            {
                log.write_action("User confirmed their input information");
                try
                {
                    my_str name(temp_name);
                    int age = 0;
                    for (int i = 0; temp_age[i] != '\0'; i++)
                    {
                        if (!isdigit(temp_age[i]))
                        {
                            throw my_str("Age must be numeric.");
                        }
                        age = age * 10 + (temp_age[i] - '0');
                    }

                    int day = 0;
                    int month = 0;
                    int yr = 0;

                    for (int i = 0; temp_d[i] != '\0'; i++)
                    {
                        if (!isdigit(temp_d[i]))
                        {
                            throw my_str("Day must be numeric.");
                        }
                        day = day * 10 + (temp_d[i] - '0');
                    }

                    for (int i = 0; temp_mon[i] != '\0'; i++)
                    {
                        if (!isdigit(temp_mon[i]))
                        {
                            throw my_str("Month must be numeric.");
                        }
                        month = month * 10 + (temp_mon[i] - '0');
                    }

                    for (int i = 0; temp_yr[i] != '\0'; i++)
                    {
                        if (!isdigit(temp_yr[i]))
                        {
                            throw my_str("Year must be numeric.");
                        }
                        yr = yr * 10 + (temp_yr[i] - '0');
                    }

                    if (age <= 0 || age > 120)
                        throw 1;

                    date dob(yr, month, day);
                    person temp_person(name, age, gender, dob);
                    person_prof = temp_person;
                    cout << person_prof << "\n";
                    currentScreen = DETECTIVE_PROF;
                }

                catch (const my_str& msg)
                {
                    log.write_error(msg.get_cs());
                    cout << "Input Error: " << msg << "\n";
                }

                catch (int error)
                {
                    if (error == 1)
                        cout << "Input Error: Invalid age.\n";
                    else
                        cout << "Input Error: Unknown input error.\n";
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == DETECTIVE_PROF)
        {
            Rectangle btn_back_instructions1 = { 620, 560, 150, 30 };
            my_str rem(", create a profile for yourself");
            my_str display_str = person_prof.get_name().concat(rem);
            DrawText(display_str.get_cs(), 50, 40, 20, YELLOW);
            detective prof1(person_prof, 85, "Behavioral Analysis", "Profiler");
            detective prof2(person_prof, 90, "Physical Evidence Analysis", "Forensics");
            detective prof3(person_prof, 75, "Interrogation & Scouting", "Field Agent");
            detective prof4(person_prof, 80, "Digital Forensics", "Cybercrime");

            Rectangle sqr1 = { 100,100,160,160 };
            Rectangle sqr2 = { 500,100,160,160 };
            Rectangle sqr3 = { 100,350,160,160 };
            Rectangle sqr4 = { 500,350,160,160 };

            DrawTexturePro(txdet1, { 0, 0, (float)txdet1.width, (float)txdet1.height }, sqr1, { 0, 0 }, 0.0f, WHITE);
            DrawTexturePro(txdet2, { 0, 0, (float)txdet2.width, (float)txdet2.height }, sqr2, { 0, 0 }, 0.0f, WHITE);
            DrawTexturePro(txdet3, { 0, 0, (float)txdet3.width, (float)txdet3.height }, sqr3, { 0, 0 }, 0.0f, WHITE);
            DrawTexturePro(txdet4, { 0, 0, (float)txdet4.width, (float)txdet4.height }, sqr4, { 0, 0 }, 0.0f, WHITE);

            Rectangle btndet1 = { sqr1.x + 30, sqr1.y + 170, 100, 30 };
            Rectangle btndet2 = { sqr2.x + 30, sqr2.y + 170, 100, 30 };
            Rectangle btndet3 = { sqr3.x + 30, sqr3.y + 170, 100, 30 };
            Rectangle btndet4 = { sqr4.x + 30, sqr4.y + 170, 100, 30 };

            GuiButton(btndet1, "Profiler");
            GuiButton(btndet2, "Forensics");
            GuiButton(btndet1, "Field Agent");
            GuiButton(btndet1, "Cyber Crime");
            //DrawText("Specialty: Behavioral Analysis", 109, 275, 10, GRAY);
            //DrawText("Experience: 85/100", 109, 300, 10, LIGHTGRAY);
            if (GuiButton(btndet1, "Profiler"))
            {
                log.write_action("User chose their detective profile.");
                detective_prof = prof1;
            }

            if (GuiButton(btndet2, "Forensics"))
            {
                log.write_action("User chose their detective profile.");
                detective_prof = prof2;
            }

            if (GuiButton(btndet3, "Field Agent"))
            {
                log.write_action("User chose their detective profile.");
                detective_prof = prof3;
            }

            if (GuiButton(btndet4, "Cyber Crime"))
            {
                log.write_action("User chose their detective profile.");
                detective_prof = prof4;
            }

            if(GuiButton(btn_back_instructions1,"Next"))
                currentScreen = DET_PROF_VIEW;
        }

        else if (currentScreen == DET_PROF_VIEW)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Detective Profile:", 50, 40, 28, YELLOW);
            DrawText("Name: ", 50, 100, 24, WHITE);
            DrawText(person_prof.get_name().get_cs(), 125, 100, 24, WHITE);
            DrawText("Age: ", 50, 150, 24, WHITE);
            DrawText(temp_age, 110, 150, 24, WHITE);
            DrawText("Gender: ", 50, 200, 24, WHITE);
            if (gender == 'M')
                DrawText("Male", 150, 200, 24, WHITE);
            else if (gender == 'F')
                DrawText("Female", 150, 200, 24, WHITE);

            DrawText("DOB: ", 50, 250, 24, WHITE);
            DrawText(temp_d, 107, 250, 24, WHITE);
            DrawText(" /", 115, 250, 24, WHITE);
            DrawText(temp_mon, 145, 250, 24, WHITE);
            DrawText(" /", 155, 250, 24, WHITE);
            DrawText(temp_yr, 182, 250, 24, WHITE);
            DrawText("Role: ", 50, 300, 24, WHITE);
            DrawText(detective_prof.get_role().get_cs(), 115, 300, 24, WHITE);
            DrawText("Specialty: ", 50, 350, 24, WHITE);
            DrawText(detective_prof.get_specialty().get_cs(), 170, 350, 24, WHITE);
            my_str exp_str(detective_prof.get_exp());
            DrawText("Experience Points: ", 50, 400, 24, WHITE);
            DrawText(exp_str.get_cs(), 275, 400, 24, WHITE);

            if (GuiButton(btn_back_instructions, "Next"))
                currentScreen = DIFFICULTY;
        }

        else if (currentScreen == DIFFICULTY)
        {
            DrawText("Choose Difficulty:", 50, 40, 28, YELLOW);
            if (GuiButton(btnStart, "Easy"))
            {
                log.write_action("User chose Easy Difficulty.");
                currentScreen = EASY;
            }
            if (GuiButton(btnInstructions, "Medium"))
            {
                log.write_action("User chose Medium Difficulty.");
                currentScreen = MEDIUM;
            }

            if (GuiButton(btnExit, "Hard"))
            {
                log.write_action("User chose Hard Difficulty.");
                currentScreen = HARD;
            }
            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = INPUT_INFO;
        }

        else if (currentScreen == EASY)
        {
            my_str case_title("The Poisoned Toast");
            my_str case_descr("Arthur Green, a wealthy retired professor, was found dead at his breakfast table.He appeared to have died while eating his morning toast.Toxicology confirmed poisoning.Only three people were home : his wife, his brother, and the maid.Each claims to have been busy with something else.The toast tray, butter dish, and trash might hold more than just breakfast clues.Can you figure out who served death for breakfast ? ");

            int house_no = 47;
            my_str society("Maplewood Residences");
            my_str city("Oakridge");
            my_str country("Everdale");
            address addr(house_no, city, society, country);

            alibi a1("I was jogging in the park from 7:00 to 8:30 AM. I returned around 8:40 and saw Clara outside taking out the trash.", "City Park", 7, 8, 30, "Clara Miles", true);
            suspect susp1("Emily Green", 42, 'F', 12, 3, 1983, "Author", "Wife", a1, false);

            alibi a2("I was on a business call in the guest bedroom from 7:00 to 9:00 AM. Clara brought me coffee at 8:00.", "Guest Bedroom", 7, 9, 12, "Clara Miles", true);
            suspect susp2("Peter Green", 38, 'M', 27, 8, 1986, "Businessman", "Younger Brother", a2, false);

            alibi a3("I cleaned the kitchen from 7:00 to 8:00 AM, then brought coffee to Peter at 8:00. I took out the trash around 8:30 and saw Emily return.", "Kitchen", 7, 8, 30, "Peter Green", false);
            suspect susp3("Clara Miles", 29, 'F', 5, 11, 1995, "Housemaid", "Housemaid", a3, true);

            suspect* t_suspects = new suspect[3];
            t_suspects[0] = susp1;
            t_suspects[1] = susp2;
            t_suspects[2] = susp3;

            dynamic_array<suspect> suspects(t_suspects, 3);

            clue cl1("The half-eaten toast on Arthur's plate tested positive for poison.", false);
            dynamic_array<clue> clues1(1, cl1);
            game_obj obj1("Poisoned Toast", true, false, clues1);
            game_obj obj2("Desk Drawer", false, false, no_clue);
            game_obj obj3("Bookshelf", false, false, no_clue);

            game_obj* gobjs1 = new game_obj[3];
            gobjs1[0] = obj1;
            gobjs1[1] = obj2;
            gobjs1[2] = obj3;
            dynamic_array<game_obj> game_objs1(gobjs1, 3);

            room r1("Study", game_objs1);

            clue cl2("The butter used on the toast contained poison, has Claras fingerprints.", false);
            dynamic_array<clue> clues2(1, cl2);
            game_obj obj4("Butter Dish", true, false, clues2);

            clue cl3("An empty poison pack prescribed to Clara found in the kitchen trash.", false);
            dynamic_array<clue> clues3(1, cl3);
            game_obj obj5("Trash Bin", true, false, clues3);

            game_obj obj6("Sink", false, false, no_clue);

            game_obj* gobjs2 = new game_obj[3];
            gobjs2[0] = obj4;
            gobjs2[1] = obj5;
            gobjs2[2] = obj6;

            dynamic_array<game_obj> game_objs2(gobjs2, 3);
            room r2("Kitchen", game_objs2);

            clue cl4("A clean coffee tray with an unused cup in Peters room. He didnt drink any.", false);
            dynamic_array<clue> clues4(1, cl4);
            game_obj obj7("Coffee Tray", true, false, clues4);

            clue cl5("Peters call log confirms a business call from 7:00 to 9 : 00 AM.", false);
            dynamic_array<clue> clues5(1, cl5);
            game_obj obj8("Call Log Printout", true, false, clues5);

            game_obj obj9("Wardrobe", false, false, no_clue);

            game_obj* gobjs3 = new game_obj[3];
            gobjs3[0] = obj7;
            gobjs3[1] = obj8;
            gobjs3[2] = obj9;
            dynamic_array<game_obj> game_objs3(gobjs3, 3);

            room r3("Guest Bedroom", game_objs3);

            room* t_rooms = new room[3];
            t_rooms[0] = r1;
            t_rooms[1] = r2;
            t_rooms[2] = r3;
            dynamic_array<room> rooms(t_rooms, 3);

            investigation iobj(case_title, case_descr, addr, suspects, rooms);

            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText(case_title.get_cs(), 240, 20, 36, GOLD);
            DrawText("Arthur Green, a wealthy retired professor, was found dead at his breakfast table. He appeared", 70, 100, 15, LIGHTGRAY);
            DrawText("to have died while eating his morning toast. Toxicology confirmed poisoning. Only three people", 70, 120, 15, LIGHTGRAY);
            DrawText("were home: his wife, his brother, and the maid. Each claims to have been busy with something else.", 70, 138, 15, LIGHTGRAY);
            DrawText("Can you figure out who served death for breakfast?", 70, 160, 15, LIGHTGRAY);

            Rectangle btnsuspects{ 250, 250, 150, 60 };
            Rectangle btnrooms{ 450,250,150,60 };
            Rectangle btnevid{ 250,350,150,60 };
            Rectangle btnaccusation{ 450,350,150,60 };
            ezobj = iobj;
            if (GuiButton(btnsuspects, "View Suspects"))
            {
                log.write_action("User is viewing suspects.");
                currentScreen = VIEW_SUSPECT_EASY;
            }

            if (GuiButton(btnrooms, "Search Rooms"))
            {
                log.write_action("User is searching rooms.");
                currentScreen = SEARCH_ROOMS_EASY;
            }

            if (GuiButton(btnevid, "View Evidences"))
            {
                log.write_action("User is viewing evidences.");
                currentScreen = VIEW_EVIDENCE_EASY;
            }

            if (GuiButton(btnaccusation, "Make Accusation"))
            {
                log.write_action("User is making an accusation.");
                currentScreen = MAKING_ACCUSATION_EASY;
            }

            if (GuiButton(btn_back_instructions, "Back"))
            {
                currentScreen = DIFFICULTY;
            }
        }

        else if (currentScreen == VIEW_SUSPECT_EASY)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            DrawText("Choose a suspect to examine in more detail: ", 100, 100, 20, LIGHTGRAY);

            Rectangle src1 = { 0, 0, (float)txezsusp1.width, (float)txezsusp1.height };
            Rectangle dest1 = { 80, 200, 150, 200 };
            Vector2 origin1 = { 0, 0 };
            DrawTexturePro(txezsusp1, src1, dest1, origin1, 0.0f, WHITE);

            Rectangle emily{ 110,430,100,30 };
            if (GuiButton(emily, ezobj.get_suspects().at(0).get_name().get_cs()))
            {
                log.write_action("User chose suspect 1.");
                currentScreen = EZSUSP1;
            }

            Rectangle src2 = { 0, 0, (float)txezsusp2.width, (float)txezsusp2.height };
            Rectangle dest2 = { 325, 200, 150, 200 };
            Vector2 origin2 = { 0, 0 };
            DrawTexturePro(txezsusp2, src2, dest2, origin2, 0.0f, WHITE);
            Rectangle peter{ 355, 430, 100, 30 };
            if (GuiButton(peter, ezobj.get_suspects().at(1).get_name().get_cs()))
            {
                log.write_action("User chose suspect 2.");
                currentScreen = EZSUSP2;
            }

            Rectangle src3 = { 0, 0, (float)txezsusp3.width, (float)txezsusp3.height };
            Rectangle dest3 = { 570, 200, 150, 200 };
            Vector2 origin3 = { 0, 0 };
            DrawTexturePro(txezsusp3, src3, dest3, origin3, 0.0f, WHITE);
            Rectangle maid{ 600, 430, 100, 30 };
            if (GuiButton(maid, ezobj.get_suspects().at(2).get_name().get_cs()))
            {
                log.write_action("User chose suspect 3.");
                currentScreen = EZSUSP3;
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = EASY;
        }

        else if (currentScreen == EZSUSP1)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            dynamic_array<suspect> t_susps = ezobj.get_suspects();
            suspect temp_susp = ezobj.get_suspects().at(0);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle src1 = { 0, 0, (float)txezsusp1.width, (float)txezsusp1.height };
            Rectangle dest1 = { 570, 100, 150, 200 };
            Vector2 origin1 = { 0, 0 };
            DrawTexturePro(txezsusp1, src1, dest1, origin1, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 1.");
                currentScreen = INTEREZ1;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_EASY;
        }

        else if (currentScreen == INTEREZ1)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_ez1 = true;
            }

            if (statement_edit_ez1)
                DrawText(ezobj.get_suspects().at(0).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);


            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_ez1 = true;
            if (location_edit_ez1)
                DrawText(ezobj.get_suspects().at(0).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);


            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_ez1.itos(ezobj.get_suspects().at(0).get_alibi().get_timing().get_hr());
                temp_min_ez1.itos(ezobj.get_suspects().at(0).get_alibi().get_timing().get_min());
                temp_secs_ez1.itos(ezobj.get_suspects().at(0).get_alibi().get_timing().get_secs());
                time_edit_ez1 = true;
            }

            if (time_edit_ez1)
            {
                DrawText(temp_hr_ez1.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_ez1.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_ez1.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_ez1 = true;
            }

            if (witness_edit_ez1)
                DrawText(ezobj.get_suspects().at(0).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = EZSUSP1;
        }

        else if (currentScreen == EZSUSP2)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = ezobj.get_suspects().at(1);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle srcez2 = { 0, 0, (float)txezsusp2.width, (float)txezsusp2.height };
            Rectangle destez2 = { 570, 100, 150, 200 };
            Vector2 originez2 = { 0, 0 };
            DrawTexturePro(txezsusp2, srcez2, destez2, originez2, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 2.");
                currentScreen = INTEREZ2;
            }


            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_EASY;
        }

        else if (currentScreen == INTEREZ2)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_ez2 = true;
            }

            if (statement_edit_ez2)
                DrawText(ezobj.get_suspects().at(1).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);


            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_ez2 = true;
            if (location_edit_ez2)
                DrawText(ezobj.get_suspects().at(1).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);


            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_ez2.itos(ezobj.get_suspects().at(1).get_alibi().get_timing().get_hr());
                temp_min_ez2.itos(ezobj.get_suspects().at(1).get_alibi().get_timing().get_min());
                temp_secs_ez2.itos(ezobj.get_suspects().at(1).get_alibi().get_timing().get_secs());
                time_edit_ez2 = true;
            }

            if (time_edit_ez2)
            {
                DrawText(temp_hr_ez2.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_ez2.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_ez2.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_ez2 = true;
            }

            if (witness_edit_ez2)
                DrawText(ezobj.get_suspects().at(1).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = EZSUSP2;
        }

        else if (currentScreen == EZSUSP3)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = ezobj.get_suspects().at(2);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);

            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle srcez3 = { 0, 0, (float)txezsusp3.width, (float)txezsusp3.height };
            Rectangle destez3 = { 570, 100, 150, 200 };
            Vector2 originez3 = { 0, 0 };
            DrawTexturePro(txezsusp3, srcez3, destez3, originez3, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 3.");
                currentScreen = INTEREZ3;
            }


            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_EASY;
        }

        else if (currentScreen == INTEREZ3)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 60,100,100,100 };
            Rectangle btn_location{ 60, 180, 150, 40 };
            Rectangle btn_time{ 60,240,150,40 };
            Rectangle btn_witness{ 60,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_ez3 = true;
            }

            if (statement_edit_ez3)
            {
                DrawText(ezobj.get_suspects().at(2).get_alibi().get_statement().get_cs(), 60, 170, 10, GRAY);
            }


            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_ez3 = true;
            if (location_edit_ez3)
                DrawText(ezobj.get_suspects().at(2).get_alibi().get_location().get_cs(), 60, 220, 10, GRAY);


            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_ez3.itos(ezobj.get_suspects().at(2).get_alibi().get_timing().get_hr());
                temp_min_ez3.itos(ezobj.get_suspects().at(2).get_alibi().get_timing().get_min());
                temp_secs_ez3.itos(ezobj.get_suspects().at(2).get_alibi().get_timing().get_secs());
                time_edit_ez3 = true;
            }

            if (time_edit_ez3)
            {
                DrawText(temp_hr_ez3.get_cs(), 60, 280, 10, GRAY);
                DrawText(":", 70, 280, 10, GRAY);
                DrawText(temp_min_ez3.get_cs(), 80, 280, 10, GRAY);
                DrawText(":", 90, 280, 10, GRAY);
                DrawText(temp_secs_ez3.get_cs(), 100, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_ez3 = true;
            }

            if (witness_edit_ez3)
                DrawText(ezobj.get_suspects().at(2).get_alibi().get_witness().get_cs(), 60, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = EZSUSP3;
        }

        else if (currentScreen == SEARCH_ROOMS_EASY)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Rooms", 350, 20, 36, GOLD);
            DrawText("Select a room to investigate: ", 60, 100, 20, LIGHTGRAY);

            dynamic_array<room> temp_rooms = ezobj.get_rooms();

            for (int i = 0; i < temp_rooms.size(); ++i)
            {
                Rectangle roomBtn = { 300, 150+ i * 100, 220, 60 };

                if (GuiButton(roomBtn, temp_rooms.at(i).get_name().get_cs()))
                {
                    if (i == 0)
                    {
                        log.write_action("User is searching room 1.");
                        currentScreen = R1EZ;
                    }

                    else if (i == 1)
                    {
                        log.write_action("User is searching room 1.");
                        currentScreen = R2EZ;
                    }

                    else if (i == 2)
                    {
                        log.write_action("User is searching room 1.");
                        currentScreen = R3EZ;
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = EASY;
        }

        else if (currentScreen == R1EZ)
        {
            Rectangle src = { 0, 0, (float)txez1study.width, (float)txez1study.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txez1study, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(ezobj.get_rooms().at(0).get_name().get_cs(), 350, 20, 36, DARKBROWN);
            dynamic_array<game_obj> t_objs = ezobj.get_rooms().at(0).get_objs();

            static bool object_clicked[3] = { false, false, false };
            static bool clue_revealed[3] = { false, false, false };
            static bool clue_write[3] = { false, false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);

                        if (!clue_write[i])
                        {
                            ofstream fout("easy_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }
            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_EASY;
        }

        else if (currentScreen == R2EZ)
        {
            Rectangle src = { 0, 0, (float)txez1kitchen.width, (float)txez1kitchen.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txez1kitchen, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(ezobj.get_rooms().at(1).get_name().get_cs(), 350, 20, 36, DARKBROWN);
            dynamic_array<game_obj> t_objs = ezobj.get_rooms().at(1).get_objs();

            static bool object_clicked[3] = { false, false, false };
            static bool clue_revealed[3] = { false, false, false };
            static bool clue_write[3] = { false, false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("easy_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }
            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_EASY;
        }

        else if (currentScreen == R3EZ)
        {
            Rectangle src = { 0, 0, (float)txez1bedroom.width, (float)txez1bedroom.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txez1bedroom, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(ezobj.get_rooms().at(2).get_name().get_cs(), 300, 20, 36, RAYWHITE);
            dynamic_array<game_obj> t_objs = ezobj.get_rooms().at(2).get_objs();

            static bool object_clicked[3] = { false, false, false };
            static bool clue_revealed[3] = { false, false, false };
            static bool clue_write[3] = { false, false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("easy_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }
            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_EASY;
        }

        else if (currentScreen == VIEW_EVIDENCE_EASY)
        {
            DrawText("Evidences", 300, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.6f));
            
            ifstream fin("easy_evidence.txt");
            if (fin.is_open())
            {
                char arr[300]; 
                int y = 80;

                while (fin.getline(arr, 300))
                {
                    my_str line(arr);
                    if (line.get_length() > 0)
                    {
                        DrawText(line.get_cs(), 50, y, 15, LIGHTGRAY);
                        y = y+20;
                    }
                }

                fin.close();
            }
            else
            {
                DrawText("No evidence found.", 50, 80, 20, RED);
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = EASY;
        }

        else if (currentScreen == MAKING_ACCUSATION_EASY)
        {
            static int selected = -1; 
            static bool confirmation = false;

            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Who's The Killer?", 250, 20, 30, GOLD);
            DrawText("Select the suspect you believe is the murderer:", 100, 100, 20, LIGHTGRAY);

            DrawTexturePro(txezsusp1, { 0, 0, (float)txezsusp1.width, (float)txezsusp1.height }, { 80, 200, 150, 200 }, { 0, 0 }, 0.0f, WHITE);
            if (GuiButton({ 110, 430, 100, 30 }, ezobj.get_suspects().at(0).get_name().get_cs()))
            {
                selected = 0;
                confirmation = true;
            }

            DrawTexturePro(txezsusp2, { 0, 0, (float)txezsusp2.width, (float)txezsusp2.height }, { 325, 200, 150, 200 }, { 0, 0 }, 0.0f, WHITE);
            if (GuiButton({ 355, 430, 100, 30 }, ezobj.get_suspects().at(1).get_name().get_cs()))
            {
                selected = 1;
                confirmation = true;
            }

            DrawTexturePro(txezsusp3, { 0, 0, (float)txezsusp3.width, (float)txezsusp3.height }, { 570, 200, 150, 200 }, { 0, 0 }, 0.0f, WHITE);
            if (GuiButton({ 600, 430, 100, 30 }, ezobj.get_suspects().at(2).get_name().get_cs()))
            {
                selected = 2;
                confirmation = true;
            }

            if (confirmation && selected != -1)
            {
                DrawRectangle(225, 125, 350, 350, Fade(BLACK, 0.8f));
                Rectangle sure{ 250, 320, 130, 40 };
                Rectangle cancel{ 420, 320, 130, 40 };
                DrawText("Are you sure?", 320, 230, 24, GOLD);
                if (GuiButton(sure, "Yes, I am sure"))
                {
                    log.write_action("User made an accusation.");
                    if (ezobj.get_suspects().at(selected).get_is_killer())
                    {
                        log.write_action("User won.");
                        currentScreen = EASY_WIN;
                    }

                    else
                    {
                        log.write_action("User lost.");
                        currentScreen = EASY_LOSE;
                    }

                    selected = -1;
                    confirmation = false;
                }

                if (GuiButton(cancel, "Cancel"))
                {
                    selected = -1;
                    confirmation = false;
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
            {
                currentScreen = EASY;
                selected = -1;
                confirmation = false;
            }
        }

        else if (currentScreen == EASY_WIN)
        {
            int susp_num = ezobj.get_suspects().size();
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            my_str temp_name;
            DrawText("YOU WON!", 280, 150, 60, GREEN);
            for (int i = 0;i < susp_num;i++)
            {
                if (ezobj.get_suspects().at(i).get_is_killer())
                {
                    temp_name = ezobj.get_suspects().at(i).get_name();
                    break;
                }
            }

            DrawText(temp_name.get_cs(), 250, 250, 30, RAYWHITE);
            DrawText("is the killer!", 440, 250, 30, RAYWHITE);

            if (GuiButton(btn_back_instructions, "Exit"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == EASY_LOSE)
        {
            int susp_num = ezobj.get_suspects().size();
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            my_str temp_name;
            DrawText("YOU LOSE!", 280, 150, 60, RED);
            for (int i = 0;i < susp_num;i++)
            {
                if (ezobj.get_suspects().at(i).get_is_killer())
                {
                    temp_name = ezobj.get_suspects().at(i).get_name();
                    break;
                }
            }

            DrawText(temp_name.get_cs(), 250, 250, 30, RAYWHITE);
            DrawText("is the killer!", 440, 250, 30, RAYWHITE);

            if (GuiButton(btn_back_instructions, "Exit"))
                currentScreen = MAIN_MENU;
        }
        
        else if (currentScreen == MEDIUM)
        {
            my_str case_title("The Final Verdict");
            my_str case_descr("Retired Judge Harold Holloway was found dead in his estate after hosting a private dinner with a few close associates. A respected man with a legacy of controversial decisions, Harold had recently hinted at writing a tell-all memoir. He was found in his study, slumped over his desk, poisoned. What seemed like natural causes was later ruled out when a rare fast-acting toxin was discovered in his system.");

            alibi a1("I was in my bedroom all evening, writing in my journal.", "Bedroom", 20, 0, 0, "None", false);
            alibi a2("I was sorting out old legal files Judge asked me to review.", "Archives Room", 19, 45, 36, "Rosa Delgado", true);
            alibi a3("I was cleaning the dining room. I saw Leonard go into the archives.", "Dining Room", 19, 30, 00, "Dr. Ellis Moore", true);
            alibi a4("I was preparing the Judges herbal tea. He had a specific routine.", "Kitchen", 20, 10, 00, "None", false);
            alibi a5("I was taking a walk, thinking about old times.", "Garden", 20, 15, 36, "None", false);

            suspect susp1("Clara Whitmore", 26, 'F', 12, 4, 1994, "Legal Intern", "Mentored by the Judge during her studies", a1, false);
            suspect susp2("Leonard Barnes", 52, 'M', 2, 11, 1973, "Court Clerk", "Long-time assistant and confidant", a2, false);
            suspect susp3("Rosa Delgado", 47, 'F', 30, 6, 1978, "Housekeeper", "Housemaid of the Judge for over 10 years", a3, false);
            suspect susp4("Dr. Ellis Moore", 58, 'M', 18, 1, 1967, "Family Physician", "Old friend and personal doctor", a4, true);
            suspect susp5("Edgar Pierce", 64, 'M', 22, 8, 1961, "Retired Lawyer", "Former law partner, estranged", a5, false);

            suspect* temp_susp = new suspect[5];
            temp_susp[0] = susp1;
            temp_susp[1] = susp2;
            temp_susp[2] = susp3;
            temp_susp[3] = susp4;
            temp_susp[4] = susp5;

            dynamic_array<suspect> suspects(temp_susp, 5);

            clue cl1("One file had a red mark,Claras fathers case, sentenced by Holloway.",false);
            dynamic_array<clue> clue1(1, cl1);
            game_obj obj1("Case Files",true,false, clue1);

            game_obj obj2("Fountain Pen",false,false,no_clue);

            clue cl2(" Inside: Only a medical report and a torn letter remain, rest is missing.", false);
            dynamic_array<clue> clue2(1, cl2);
            game_obj obj3("Wall Safe(opened)", true, false, clue2);

            game_obj* r1_objs = new game_obj[3];
            r1_objs[0] = obj1;
            r1_objs[1] = obj2;
            r1_objs[2] = obj3;
            dynamic_array<game_obj> r1objs(r1_objs, 3);

            room r1("Judges Study", r1objs);

            game_obj obj4("Cheese Platter", false, false, no_clue);

            clue cl5("One wine glass had traces of a sedative, not lethal", false);
            dynamic_array<clue> clue5(1, cl5);
            game_obj obj5("Wine Glasses", true, false, clue5);

            clue cl6("Judges chair was pushed back sharply, hence, sudden physical reaction.", true);
            dynamic_array<clue> clue6(1, cl6);
            game_obj obj6("Chair (pushed back)", true, false, clue6);

            game_obj* r2_objs = new game_obj[3];
            r2_objs[0] = obj4;
            r2_objs[1] = obj5;
            r2_objs[2] = obj6;
            dynamic_array<game_obj> r2objs(r2_objs, 3);

            room r2("Dining Room", r2objs);

            clue cl7("Hidden email shows Claras anger over her fathers conviction,blaming Judge.", true);
            dynamic_array<clue> clue7(1, cl7);
            game_obj obj7("Claras Suitcase", true, false, clue7);

            game_obj obj8("Travel Brochure", false, false, no_clue);

            game_obj* r3_objs = new game_obj[2];
            r3_objs[0] = obj7;
            r3_objs[1] = obj8;
            dynamic_array<game_obj> r3objs(r3_objs, 2);

            room r3("Guest Bedroom", r3objs);

            clue cl8("A single blue colored glove with wine stains,.", false);
            dynamic_array<clue> clue8(1, cl8);
            game_obj obj9("Dropped Glove", true, false, clue8);

            game_obj obj10("Coat Rack", false, false, no_clue);

            game_obj* r4_objs = new game_obj[2];
            r4_objs[0] = obj9;
            r4_objs[1] = obj10;
            dynamic_array<game_obj> r4objs(r4_objs, 2);

            room r4("Hallway", r4objs);

            clue cl9("Shirt belonging to Leonard had wine and sedative traces.", true);
            dynamic_array<clue> clue9(1, cl9);
            game_obj obj11("Shirt with wine stain", true, false, clue9);

            clue cl10("Empty vial marked Compound 13B,a sedative used in medical treatments.", false);
            dynamic_array<clue> clue10(1, cl10);
            game_obj obj12("Empty Basket", true, false, clue10);

            game_obj* r5_objs = new game_obj[2];
            r5_objs[0] = obj11;
            r5_objs[1] = obj12;
            dynamic_array<game_obj> r5objs(r5_objs, 2);

            room r5("Laundry Room", r5objs);

            room* temp_rooms = new room[5];
            temp_rooms[0] = r1;
            temp_rooms[1] = r2;
            temp_rooms[2] = r3;
            temp_rooms[3] = r4;
            temp_rooms[4] = r5;

            dynamic_array<room> rooms(temp_rooms, 5);

            address addr(221, "London", "Barristers Row", "UK");
            dynamic_array<game_obj> evidence;
            investigation temp_medobj(case_title, case_descr, addr, suspects, rooms);
            medium_obj = temp_medobj;

            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText(case_title.get_cs(), 240, 20, 36, GOLD);
            DrawText("Retired Judge Harold Holloway was found dead in his estate after hosting a private dinner with a", 50, 100, 15, LIGHTGRAY);
            DrawText("few close associates. A respected man with a legacy of controversial decisions, Harold had recently", 50, 120, 15, LIGHTGRAY);
            DrawText("hinted at writing a tell-all memoir. He was found in dining room, slumped over the tanle, poisoned. What", 50, 138, 15, LIGHTGRAY);
            DrawText("seemed like natural causes was later ruled out when a rare fast-acting toxin was discovered in his", 50, 160, 15, LIGHTGRAY);
            DrawText("system", 50, 175, 15, LIGHTGRAY);

            Rectangle btnsuspects{ 250, 250, 150, 60 };
            Rectangle btnrooms{ 450,250,150,60 };
            Rectangle btnevid{ 250,350,150,60 };
            Rectangle btnaccusation{ 450,350,150,60 };
            if (GuiButton(btnsuspects, "View Suspects"))
            {
                log.write_action("User is viewing suspects.");
                currentScreen = VIEW_SUSPECT_MED;
            }

            if (GuiButton(btnrooms, "Search Rooms"))
            {
                log.write_action("User is searching rooms.");
                currentScreen = SEARCH_ROOMS_MED;
            }

            if (GuiButton(btnevid, "View Evidences"))
            {
                log.write_action("User is viewing evidences.");
                currentScreen = VIEW_EVIDENCE_MED;
            }

            if (GuiButton(btnaccusation, "Make Accusation"))
            {
                log.write_action("User is making an accusation.");
                currentScreen = MAKING_ACCUSATION_MED;
            }

            if (GuiButton(btn_back_instructions, "Back"))
            {
                currentScreen = DIFFICULTY;
            }
        }

        else if (currentScreen == VIEW_SUSPECT_MED)
        {
            DrawText("Suspects", 260, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Select the suspect for further investigation", 100, 100, 20, LIGHTGRAY);

            Rectangle src1 = { 0, 0, (float)txmedsusp1.width, (float)txmedsusp1.height };
            Rectangle dest1 = { 70, 150, 125, 125 };
            Vector2 origin1 = { 0, 0 };
            DrawTexturePro(txmedsusp1, src1, dest1, origin1, 0.0f, WHITE);
            Rectangle sp1{ 80, 300, 100, 30 };
            if (GuiButton(sp1, medium_obj.get_suspects().at(0).get_name().get_cs()))
            {
                log.write_action("User chose suspect 1.");
                currentScreen = MEDSUSP1;
            }

            Rectangle src2 = { 0, 0, (float)txmedsusp2.width, (float)txmedsusp2.height };
            Rectangle dest2 = { 300, 150, 140, 140 };
            Vector2 origin2 = { 0, 0 };
            DrawTexturePro(txmedsusp2, src2, dest2, origin2, 0.0f, WHITE);
            Rectangle sp2{ 320, 300, 100, 30 };
            if (GuiButton(sp2, medium_obj.get_suspects().at(1).get_name().get_cs()))
            {
                log.write_action("User chose suspect 2.");
               currentScreen = MEDSUSP2;
            }

            Rectangle src3 = { 0, 0, (float)txmedsusp3.width, (float)txmedsusp3.height };
            Rectangle dest3 = { 550, 150, 125, 125 };
            Vector2 origin3 = { 0, 0 };
            DrawTexturePro(txmedsusp3, src3, dest3, origin3, 0.0f, WHITE);
            Rectangle sp3{ 560, 300, 100, 30 };
            if (GuiButton(sp3, medium_obj.get_suspects().at(2).get_name().get_cs()))
            {
                log.write_action("User chose suspect 3.");
                currentScreen = MEDSUSP3;
            }

            Rectangle src4 = { 0, 0, (float)txmedsusp4.width, (float)txmedsusp4.height };
            Rectangle dest4 = { 190, 355, 125, 125 };
            Vector2 origin4 = { 0, 0 };
            DrawTexturePro(txmedsusp4, src4, dest4, origin4, 0.0f, WHITE);
            Rectangle sp4{ 200, 495, 100, 30 };
            if (GuiButton(sp4, medium_obj.get_suspects().at(3).get_name().get_cs()))
            {
                log.write_action("User chose suspect 4.");
                currentScreen = MEDSUSP4;
            }

            Rectangle src5 = { 0, 0, (float)txmedsusp5.width, (float)txmedsusp5.height };
            Rectangle dest5 = { 425, 320, 170, 170 };
            Vector2 origin5 = { 0, 0 };
            DrawTexturePro(txmedsusp5, src5, dest5, origin5, 0.0f, WHITE);
            Rectangle sp5{ 465, 495, 100, 30 };
            if (GuiButton(sp5, medium_obj.get_suspects().at(4).get_name().get_cs()))
            {
                log.write_action("User chose suspect 5.");
                currentScreen = MEDSUSP5;
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDIUM;
        }

        else if (currentScreen == MEDSUSP1)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = medium_obj.get_suspects().at(0);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txmedsusp1.width, (float)txmedsusp1.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedsusp1, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 1");
                currentScreen = INTERMED1;
            }


            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_MED;
        }

        else if (currentScreen == MEDSUSP2)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = medium_obj.get_suspects().at(1);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txmedsusp2.width, (float)txmedsusp2.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedsusp2, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 2");
                currentScreen = INTERMED2;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_MED;
        }

        else if (currentScreen == MEDSUSP3)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = medium_obj.get_suspects().at(2);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txmedsusp3.width, (float)txmedsusp3.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedsusp3, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 3");
                currentScreen = INTERMED3;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_MED;
        }

        else if (currentScreen == MEDSUSP4)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = medium_obj.get_suspects().at(3);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txmedsusp4.width, (float)txmedsusp4.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedsusp4, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 4");
                currentScreen = INTERMED4;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_MED;
        }

        else if (currentScreen == MEDSUSP5)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = medium_obj.get_suspects().at(4);

            DrawText("Name: ", 100, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 170, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 100, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 150, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 100, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 180, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 180, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 100, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 175, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("/", 210, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 230, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 100, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 225, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 100, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 350, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txmedsusp5.width, (float)txmedsusp5.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedsusp5, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 5");
                currentScreen = INTERMED5;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_MED;
        }

        else if (currentScreen == INTERMED1)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_med1 = true;
            }

            if (statement_edit_med1)
                DrawText(medium_obj.get_suspects().at(0).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);


            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_med1 = true;
            if (location_edit_med1)
                DrawText(medium_obj.get_suspects().at(0).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);


            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_med1.itos(medium_obj.get_suspects().at(0).get_alibi().get_timing().get_hr());
                temp_min_med1.itos(medium_obj.get_suspects().at(0).get_alibi().get_timing().get_min());
                temp_secs_med1.itos(medium_obj.get_suspects().at(0).get_alibi().get_timing().get_secs());
                time_edit_med1 = true;
            }

            if (time_edit_med1)
            {
                DrawText(temp_hr_med1.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_med1.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_med1.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_med1 = true;
            }

            if (witness_edit_med1)
                DrawText(medium_obj.get_suspects().at(0).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDSUSP1;
        }

        else if (currentScreen == INTERMED2)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_med2 = true;
            }

            if (statement_edit_med2)
                DrawText(medium_obj.get_suspects().at(1).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);


            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_med2 = true;
            if (location_edit_med2)
                DrawText(medium_obj.get_suspects().at(1).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_med2.itos(medium_obj.get_suspects().at(1).get_alibi().get_timing().get_hr());
                temp_min_med2.itos(medium_obj.get_suspects().at(1).get_alibi().get_timing().get_min());
                temp_secs_med2.itos(medium_obj.get_suspects().at(1).get_alibi().get_timing().get_secs());
                time_edit_med2 = true;
            }

            if (time_edit_med2)
            {
                DrawText(temp_hr_med2.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_med2.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_med2.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_med2 = true;
            }

            if (witness_edit_med2)
                DrawText(medium_obj.get_suspects().at(1).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDSUSP2;
        }

        else if (currentScreen == INTERMED3)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_med3 = true;
            }

            if (statement_edit_med3)
                DrawText(medium_obj.get_suspects().at(2).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_med3 = true;
            if (location_edit_med3)
                DrawText(medium_obj.get_suspects().at(2).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_med3.itos(medium_obj.get_suspects().at(2).get_alibi().get_timing().get_hr());
                temp_min_med3.itos(medium_obj.get_suspects().at(2).get_alibi().get_timing().get_min());
                temp_secs_med3.itos(medium_obj.get_suspects().at(2).get_alibi().get_timing().get_secs());
                time_edit_med3 = true;
            }

            if (time_edit_med3)
            {
                DrawText(temp_hr_med3.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_med3.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_med3.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_med3 = true;
            }

            if (witness_edit_med3)
                DrawText(medium_obj.get_suspects().at(2).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDSUSP3;
        }

        else if (currentScreen == INTERMED4)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_med4 = true;
            }

            if (statement_edit_med4)
                DrawText(medium_obj.get_suspects().at(3).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_med4 = true;
            if (location_edit_med4)
                DrawText(medium_obj.get_suspects().at(3).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_med4.itos(medium_obj.get_suspects().at(3).get_alibi().get_timing().get_hr());
                temp_min_med4.itos(medium_obj.get_suspects().at(3).get_alibi().get_timing().get_min());
                temp_secs_med4.itos(medium_obj.get_suspects().at(3).get_alibi().get_timing().get_secs());
                time_edit_med4 = true;
            }

            if (time_edit_med4)
            {
                DrawText(temp_hr_med4.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_med4.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_med4.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_med4 = true;
            }

            if (witness_edit_med4)
                DrawText(medium_obj.get_suspects().at(3).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDSUSP4;
        }

        else if (currentScreen == INTERMED5)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_med5 = true;
            }

            if (statement_edit_med5)
                DrawText(medium_obj.get_suspects().at(4).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_med5 = true;
            if (location_edit_med5)
                DrawText(medium_obj.get_suspects().at(4).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_med5.itos(medium_obj.get_suspects().at(4).get_alibi().get_timing().get_hr());
                temp_min_med5.itos(medium_obj.get_suspects().at(4).get_alibi().get_timing().get_min());
                temp_secs_med5.itos(medium_obj.get_suspects().at(4).get_alibi().get_timing().get_secs());
                time_edit_med5 = true;
            }

            if (time_edit_med5)
            {
                DrawText(temp_hr_med5.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_med5.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_med5.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_med5 = true;
            }

            if (witness_edit_med5)
                DrawText(medium_obj.get_suspects().at(4).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDSUSP5;
        }

        else if (currentScreen == SEARCH_ROOMS_MED)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Rooms", 350, 20, 36, GOLD);
            DrawText("Select a room to investigate: ", 60, 100, 20, LIGHTGRAY);

            dynamic_array<room> temp_rooms = medium_obj.get_rooms();

            for (int i = 0; i < temp_rooms.size(); i++)
            {
                Rectangle roomBtn = { 300, 150 + i * 75, 220, 60 };

                if (GuiButton(roomBtn, temp_rooms.at(i).get_name().get_cs()))
                {
                    if (i == 0)
                    {
                        log.write_action("User is searching room 1.");
                        currentScreen = R1MED;
                    }
                    else if (i == 1)
                    {
                        log.write_action("User is searching room 2.");
                        currentScreen = R2MED;
                    }
                    else if (i == 2)
                    {
                        log.write_action("User is searching room 3.");
                        currentScreen = R3MED;
                    }
                    else if (i == 3)
                    {
                        log.write_action("User is searching room 4.");
                        currentScreen = R4MED;
                    }
                    else if (i == 4)
                    {
                        log.write_action("User is searching room 5.");
                        currentScreen = R5MED;
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDIUM;
        }

        else if (currentScreen == R1MED)
        {
            Rectangle src = { 0, 0, (float)txmedr1.width, (float)txmedr1.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedr1, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(medium_obj.get_rooms().at(0).get_name().get_cs(), 300, 20, 36, BROWN);
            dynamic_array<game_obj> t_objs = medium_obj.get_rooms().at(0).get_objs();

            static bool object_clicked[3] = { false, false, false };
            static bool clue_revealed[3] = { false, false, false };
            static bool clue_write[3] = { false, false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("med_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_MED;
        }

        else if (currentScreen == R2MED)
        {
            Rectangle src = { 0, 0, (float)txmedr2.width, (float)txmedr2.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedr2, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BEIGE, 0.4f));

            DrawText(medium_obj.get_rooms().at(1).get_name().get_cs(), 300, 20, 36, RAYWHITE);
            dynamic_array<game_obj> t_objs = medium_obj.get_rooms().at(1).get_objs();

            static bool object_clicked[3] = { false, false, false };
            static bool clue_revealed[3] = { false, false, false };
            static bool clue_write[3] = { false, false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, BLACK);
                        if (!clue_write[i])
                        {
                            ofstream fout("med_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_MED;
        }

        else if (currentScreen == R3MED)
        {
            Rectangle src = { 0, 0, (float)txmedr3.width, (float)txmedr3.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedr3, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(medium_obj.get_rooms().at(2).get_name().get_cs(), 300, 20, 36, BLACK);
            dynamic_array<game_obj> t_objs = medium_obj.get_rooms().at(2).get_objs();

            static bool object_clicked[2] = { false, false };
            static bool clue_revealed[2] = { false, false };
            static bool clue_write[2] = { false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 390, y + 10, 10, BLACK);
                        if (!clue_write[i])
                        {
                            ofstream fout("med_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_MED;
        }

        else if (currentScreen == R4MED)
        {
            Rectangle src = { 0, 0, (float)txmedr4.width, (float)txmedr4.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedr4, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(medium_obj.get_rooms().at(3).get_name().get_cs(), 340, 20, 36, BLACK);
            dynamic_array<game_obj> t_objs = medium_obj.get_rooms().at(3).get_objs();

            static bool object_clicked[2] = { false, false };
            static bool clue_revealed[2] = { false, false };
            static bool clue_write[2] = { false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 390, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("med_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_MED;
        }

        else if (currentScreen == R5MED)
        {
            Rectangle src = { 0, 0, (float)txmedr5.width, (float)txmedr5.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedr5, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(LIGHTGRAY, 0.6f));

            DrawText(medium_obj.get_rooms().at(4).get_name().get_cs(), 300, 20, 36, DARKBLUE);
            dynamic_array<game_obj> t_objs = medium_obj.get_rooms().at(4).get_objs();

            static bool object_clicked[2] = { false, false };
            static bool clue_revealed[2] = { false, false };
            static bool clue_write[2] = { false, false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;

                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, DARKBLUE);
                        if (!clue_write[i])
                        {
                            ofstream fout("med_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_MED;
        }   

        else if (currentScreen == VIEW_EVIDENCE_MED)
        {
            DrawText("Evidences", 300, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.6f));

            ifstream fin("med_evidence.txt");
            if (fin.is_open())
            {
                char arr[300];
                int y = 80;

                while (fin.getline(arr, 300))
                {
                    my_str line(arr);
                    if (line.get_length() > 0)
                    {
                        DrawText(line.get_cs(), 50, y, 15, LIGHTGRAY);
                        y = y + 20;
                    }
                }

                fin.close();
            }

            else
            {
                DrawText("No evidence found.", 50, 80, 20, RED);
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDIUM;
        }

        else if (currentScreen == MAKING_ACCUSATION_MED)
        {
            static int selected = -1;
            static bool confirmation = false;

            DrawText("Suspects", 260, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Select the suspect who you think is the murderer:", 100, 100, 20, LIGHTGRAY);

            Rectangle src1 = { 0, 0, (float)txmedsusp1.width, (float)txmedsusp1.height };
            Rectangle dest1 = { 70, 150, 125, 125 };
            Vector2 origin1 = { 0, 0 };
            DrawTexturePro(txmedsusp1, src1, dest1, origin1, 0.0f, WHITE);
            Rectangle sp1{ 80, 300, 100, 30 };
            if (GuiButton(sp1, medium_obj.get_suspects().at(0).get_name().get_cs()))
            {
                selected = 0;
                confirmation = true;
            }

            Rectangle src2 = { 0, 0, (float)txmedsusp2.width, (float)txmedsusp2.height };
            Rectangle dest2 = { 300, 150, 140, 140 };
            Vector2 origin2 = { 0, 0 };
            DrawTexturePro(txmedsusp2, src2, dest2, origin2, 0.0f, WHITE);
            Rectangle sp2{ 320, 300, 100, 30 };
            if (GuiButton(sp2, medium_obj.get_suspects().at(1).get_name().get_cs()))
            {
                selected = 1;
                confirmation = true;
            }

            Rectangle src3 = { 0, 0, (float)txmedsusp3.width, (float)txmedsusp3.height };
            Rectangle dest3 = { 550, 150, 125, 125 };
            Vector2 origin3 = { 0, 0 };
            DrawTexturePro(txmedsusp3, src3, dest3, origin3, 0.0f, WHITE);
            Rectangle sp3{ 560, 300, 100, 30 };
            if (GuiButton(sp3, medium_obj.get_suspects().at(2).get_name().get_cs()))
            {
                selected = 2;
                confirmation = true;
            }

            Rectangle src4 = { 0, 0, (float)txmedsusp4.width, (float)txmedsusp4.height };
            Rectangle dest4 = { 190, 355, 125, 125 };
            Vector2 origin4 = { 0, 0 };
            DrawTexturePro(txmedsusp4, src4, dest4, origin4, 0.0f, WHITE);
            Rectangle sp4{ 200, 495, 100, 30 };
            if (GuiButton(sp4, medium_obj.get_suspects().at(3).get_name().get_cs()))
            {
                selected = 3;
                confirmation = true;
            }

            Rectangle src5 = { 0, 0, (float)txmedsusp5.width, (float)txmedsusp5.height };
            Rectangle dest5 = { 425, 320, 170, 170 };
            Vector2 origin5 = { 0, 0 };
            DrawTexturePro(txmedsusp5, src5, dest5, origin5, 0.0f, WHITE);
            Rectangle sp5{ 465, 495, 100, 30 };
            if (GuiButton(sp5, medium_obj.get_suspects().at(4).get_name().get_cs()))
            {
                selected = 4;
                confirmation = true;
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MEDIUM;

            if (confirmation && selected != -1)
            {
                DrawRectangle(225, 125, 350, 350, Fade(BLACK, 0.8f));
                Rectangle sure{ 250, 320, 130, 40 };
                Rectangle cancel{ 420, 320, 130, 40 };
                DrawText("Are you sure?", 320, 230, 24, GOLD);
                if (GuiButton(sure, "Yes, I am sure"))
                {
                    log.write_action("User made an accusation.");
                    if (medium_obj.get_suspects().at(selected).get_is_killer())
                    {
                        log.write_action("User won.");
                        currentScreen = MED_WIN;
                    }
                    else
                    {
                        log.write_action("User lost.");
                        currentScreen = MED_LOSE;
                    }

                    selected = -1;
                    confirmation = false;
                }

                if (GuiButton(cancel, "Cancel"))
                {
                    selected = -1;
                    confirmation = false;
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
            {
                currentScreen = MEDIUM;
                selected = -1;
                confirmation = false;
            }
        }

        else if (currentScreen == MED_WIN)
        {
            int susp_num = medium_obj.get_suspects().size();
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            my_str temp_name;
            DrawText("YOU WON!", 280, 150, 60, GREEN);
            int count = 0;

            for (int i = 0;i < susp_num;i++)
            {
                if (medium_obj.get_suspects().at(i).get_is_killer())
                {
                    count++;
                    temp_name = medium_obj.get_suspects().at(i).get_name();
                    break;
                }
            }

            DrawText(temp_name.get_cs(), 205, 250, 30, RAYWHITE);
            DrawText("is the killer!", 450, 250, 30, RAYWHITE);

            if (GuiButton(btn_back_instructions, "Exit"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == MED_LOSE)
        {
            int susp_num = medium_obj.get_suspects().size();
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            my_str temp_name;
            DrawText("YOU LOSE!", 280, 150, 60, RED);
            int count = 0;

            for (int i = 0;i < susp_num;i++)
            {
                if (medium_obj.get_suspects().at(i).get_is_killer())
                {
                    count++;
                    temp_name = medium_obj.get_suspects().at(i).get_name();
                    break;
                }
            }

            DrawText(temp_name.get_cs(), 205, 250, 30, RAYWHITE);
            DrawText("is the killer!", 450, 250, 30, RAYWHITE);

            if (GuiButton(btn_back_instructions, "Exit"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == HARD)
        {
            my_str case_title("Shadows of Justice");
            my_str case_descr("Judge Victor Harland, a revered yet controversial figure in the world of criminal justice, was discovered dead in his private study after a small evening gathering with close colleagues and acquaintances. Initially presumed to be a fatal fall or natural accident. With no immediate signs of poison, the method of murder pointed toward physical trauma—calculated, intimate, and deliberate. Behind the facade of loyalty lies a tangled web of ambition, secrets, revenge, and a final act masked under the illusion of routine. As the storm brews outside, the truth remains hidden.");
            alibi a1("I was organizing photo negatives in the basement darkroom.", "Darkroom", 19, 30, 45, "Miranda Harland", true);
            suspect susp1("Carmen Doyle", 39, 'M', 7, 10, 1986, "Crime Scene Photographer", "Photographing artifacts for Harlands memoir", a1, true);

            alibi a2("I was with Carmen in the darkroom, waiting for my turn.", "Darkroom", 19, 30, 45, "Carmen Doyle", true);
            suspect susp2("Miranda Harland", 28, 'F', 22, 3, 1997, "PhD Student", "Victor Harlands only daughter", a2, false);

            alibi a3("I was in the library reviewing the biography chapters Victor asked for.", "Library", 19, 45, 00, "None", false);
            suspect susp3("Miles Hart", 45, 'M', 14, 6, 1980, "Biographer", "Commissioned to write Victors memoir", a3, false);

            alibi a4("I was in the kitchen preparing tea with the maid.", "Kitchen", 20, 0, 0, "None", false);
            suspect susp4("Vera Lin", 32, 'F', 18, 11, 1992, "Journalist", "Victors niece, wrote articles defending him", a4, false);

            alibi a5("I was resting in the guest room, jetlagged from overseas travel.", "Guestroom", 19, 50, 0, "None", false);
            suspect susp5("Gregory Shore", 54, 'M', 2, 5, 1971, "Legal Consultant", "Had recent public disputes with Victor", a5, false);

            alibi a6("I was cataloging new acquisitions in the gallery wing.", "Gallery", 20, 15, 0, "None", false);
            suspect susp6("Nadia Flint", 41, 'F', 9, 8, 1983, "Antique Dealer", "Helped Victor acquire rare court items", a6, false);

            alibi a7("I was cleaning near the pantry with Vera.", "Pantry", 20, 5, 0, "Vera Lin", true);
            suspect susp7("Omar Rafiq", 36, 'M', 29, 9, 1988, "Private Chef", "Hired to cook for Victors gathering", a7, false);

            alibi a8("I was fixing my car in the garage, as it was acting up again.", "Garage", 19, 55, 0, "Nadia Flint", true);
            suspect susp8("Bryce Holloway", 30, 'M', 4, 4, 1995, "Unemployed", "Estranged son of Victor Harland", a8, false);

            suspect* t_susps = new suspect[8];
            t_susps[0] = susp1;
            t_susps[1] = susp2;
            t_susps[2] = susp3;
            t_susps[3] = susp4;
            t_susps[4] = susp5;
            t_susps[5] = susp6;
            t_susps[6] = susp7;
            t_susps[7] = susp8;
            dynamic_array<suspect> suspects(t_susps, 8);

            clue cl1("Lens cracked, traces of ash", false);
            dynamic_array<clue> clue1(1, cl1);
            game_obj obj1("Broken Spectacles", true, false, clue1);

            game_obj obj2("Safe (closed)", false, false, no_clue);

            clue cl3("Last entry mentions C.V.", true);
            dynamic_array<clue> clue3(1, cl3);
            game_obj obj3("Old Diary", true, false, clue3);

            clue cl4("Stopped at 20:03", false);
            dynamic_array<clue> clue4(1, cl4);
            game_obj obj4("Desk Clock", true, false, clue4);

            game_obj obj5("Empty Cigar Box", false, false, no_clue);

            game_obj* gobjs1 = new game_obj[5];
            gobjs1[0] = obj1;
            gobjs1[1] = obj2;
            gobjs1[2] = obj3;
            gobjs1[3] = obj4;
            gobjs1[4] = obj5;
            dynamic_array<game_obj> gobjs_r1(gobjs1, 5);

            room r1("Study", gobjs_r1);

            clue cl5("Petal stains on floor, rare orchid used in pain inducing toxins", false);
            dynamic_array<clue> clue5(1, cl5);
            game_obj obj6("Broken Flower Pot", true, false, clue5);

            game_obj obj7("Watering Can", false, false, no_clue);
            game_obj obj8("Garden Gloves", false, false, no_clue);
            game_obj obj9("Notebook (Plant Log)", false, false, no_clue);

            game_obj* gobjs2 = new game_obj[4];
            gobjs2[0] = obj8;
            gobjs2[1] = obj7;
            gobjs2[2] = obj6;
            gobjs2[3] = obj9;
            dynamic_array<game_obj> gobjs_r2(gobjs2, 4);

            room r2("Conservatory", gobjs_r2);

            clue cl6("Wrench has dark smear, possibly blood mixed with oil", false);
            dynamic_array<clue> clue6(1, cl6);
            game_obj obj10("Heavy Wrench", true, false, clue6);

            game_obj obj11("Spare Tire", false, false, no_clue);
            game_obj obj12("Work Bench", false, false, no_clue);
            game_obj obj13("Dusty First Aid Kit", false, false, no_clue);
            game_obj obj14("Crate of Tools", false, false, no_clue);

            game_obj* gobjs3 = new game_obj[5];
            gobjs3[0] = obj11;
            gobjs3[1] = obj10;
            gobjs3[2] = obj12;
            gobjs3[3] = obj13;
            gobjs3[4] = obj14;
            dynamic_array<game_obj> gobjs_r3(gobjs3, 5);

            room r3("Garage", gobjs_r3);

            clue cl7("A torn book page mentions undone justice", true);
            dynamic_array<clue> clue7(1, cl7);
            game_obj obj15("Ripped Book Page", true, false, clue7);

            game_obj obj16("Shelf of Legal Books", false, false, no_clue);
            game_obj obj17("Lamp with Burnt Bulb", false, false, no_clue);

            game_obj* gobjs4 = new game_obj[3];
            gobjs4[0] = obj15;
            gobjs4[1] = obj16;
            gobjs4[2] = obj17;
            dynamic_array<game_obj> gobjs_r4(gobjs4, 3);

            room r4("Library", gobjs_r4);

            clue cl8("One rag has chloroform traces.", false);
            dynamic_array<clue> clue8(1, cl8);
            game_obj obj18("Pile of Rags", true, false, clue8);

            game_obj obj19("Workbench (Stained)", false, false, no_clue);
            game_obj obj20("Old Trunk", false, false, no_clue);
            game_obj obj21("Chemical Bottles", false, false, no_clue);

            game_obj* gobjs5 = new game_obj[4];
            gobjs5[0] = obj21;
            gobjs5[1] = obj19;
            gobjs5[2] = obj20;
            gobjs5[3] = obj18;
            dynamic_array<game_obj> gobjs_r5(gobjs5, 4);

            room r5("Basement", gobjs_r5);

            clue cl9("Shards of mirror found with blood traces", false);
            dynamic_array<clue> clue9(1, cl9);
            game_obj obj22("Shattered Mirror", true, false, clue9);

            game_obj obj23("Travel Suitcase", false, false, no_clue);
            game_obj obj24("Empty Bottle of Cologne", false, false, no_clue);
            game_obj obj25("Nightstand Drawer", false, false, no_clue);

            game_obj* gobjs6 = new game_obj[4];
            gobjs6[0] = obj24;
            gobjs6[1] = obj23;
            gobjs6[2] = obj22;
            gobjs6[3] = obj25;
            dynamic_array<game_obj> gobjs_r6(gobjs6, 4);

            room r6("Guest Bedroom", gobjs_r6);

            clue cl10("Cutting board had reddish residue, possibly blood.", false);
            dynamic_array<clue> clue10(1, cl10);
            game_obj obj26("Cutting Board", true, false, clue10);

            game_obj obj27("Kitchen Knife Set", false, false, no_clue);
            game_obj obj28("Fridge", false, false, no_clue);
            game_obj obj29("Used Napkin", false, false, no_clue);
            game_obj obj30("Stove (Still Warm)", false, false, no_clue);

            game_obj* gobjs7 = new game_obj[5];
            gobjs7[0] = obj30;
            gobjs7[1] = obj27;
            gobjs7[2] = obj28;
            gobjs7[3] = obj29;
            gobjs7[4] = obj26;
            dynamic_array<game_obj> gobjs_r7(gobjs7, 5);

            room r7("Kitchen", gobjs_r7);

            room* trooms = new room[7];
            trooms[0] = r1;
            trooms[1] = r2;
            trooms[2] = r3;
            trooms[3] = r4;
            trooms[4] = r5;
            trooms[5] = r6;
            trooms[6] = r7;
            dynamic_array<room> rooms(trooms, 7);

            address addr(118, "Ravenshade", "Ashcroft Estate", "Eldoria");

            investigation temp_obj(case_title, case_descr, addr, suspects, rooms);
            hard_obj = temp_obj;

            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText(case_title.get_cs(), 240, 20, 36, GOLD);
            DrawText("Judge Victor Harland, a revered yet controversial figure in the world of criminal justice, was", 50, 100, 15, LIGHTGRAY);
            DrawText("discovered dead in his private study after a small evening gathering with close colleagues and", 50, 120, 15, LIGHTGRAY);
            DrawText("acquaintances. Initially presumed to be a fatal fall or natural accident. With no immediate signs", 50, 138, 15, LIGHTGRAY);
            DrawText("of poison, the method of murder pointed toward physical trauma—calculated, intimate and deliberate.", 50, 160, 15, LIGHTGRAY);
            DrawText("Behind the facade of loyalty lies a tangled web of ambition, secrets, revenge, and a final act", 50, 175, 15, LIGHTGRAY);
            DrawText("masked under the illusion of routine. As the storm brews outside, the truth remains hidden.", 50, 190, 15, LIGHTGRAY);

            Rectangle btnsuspects{ 250, 250, 150, 60 };
            Rectangle btnrooms{ 450,250,150,60 };
            Rectangle btnevid{ 250,350,150,60 };
            Rectangle btnaccusation{ 450,350,150,60 };
            if (GuiButton(btnsuspects, "View Suspects"))
            {
                log.write_action("User is viewing suspects");
                currentScreen = VIEW_SUSPECT_HARD;
            }

            if (GuiButton(btnrooms, "Search Rooms"))
            {
                log.write_action("User is searching rooms.");
                currentScreen = SEARCH_ROOMS_HARD;
            }

            if (GuiButton(btnevid, "View Evidences"))
            {
                log.write_action("User is viewin evidences.");
                currentScreen = VIEW_EVIDENCE_HARD;
            }

            if (GuiButton(btnaccusation, "Make Accusation"))
            {
                log.write_action("User is making an accusation.");
                currentScreen = MAKING_ACCUSATION_HARD;
            }

            if (GuiButton(btn_back_instructions, "Back"))
            {
                currentScreen = DIFFICULTY;
            }
        }

        else if (currentScreen == VIEW_SUSPECT_HARD)
        {
            DrawText("Suspects", 300, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Select the suspect for further investigation", 60, 100, 20, LIGHTGRAY);

            Rectangle src1 = { 0, 0, (float)txhardsusp1.width, (float)txhardsusp1.height };
            Rectangle dest1 = { 50, 150, 125, 125 };
            Vector2 origin1 = { 0, 0 };
            DrawTexturePro(txhardsusp1, src1, dest1, origin1, 0.0f, WHITE);
            Rectangle sp1{ 60, 280, 100, 30 };
            if (GuiButton(sp1, hard_obj.get_suspects().at(0).get_name().get_cs()))
            {
                log.write_action("User chose suspect 1.");
                currentScreen = HARDSUSP1;
            }

            Rectangle src2 = { 0, 0, (float)txhardsusp2.width, (float)txhardsusp2.height };
            Rectangle dest2 = { 235, 150, 120, 120 };
            Vector2 origin2 = { 0, 0 };
            DrawTexturePro(txhardsusp2, src2, dest2, origin2, 0.0f, WHITE);
            Rectangle sp2{ 250, 280, 100, 30 };
            if (GuiButton(sp2, hard_obj.get_suspects().at(1).get_name().get_cs()))
            {
                log.write_action("User chose suspect 2.");
                currentScreen = HARDSUSP2;
            }

            Rectangle src3 = { 0, 0, (float)txhardsusp3.width, (float)txhardsusp3.height };
            Rectangle dest3 = { 430, 150, 120, 120 };
            Vector2 origin3 = { 0, 0 };
            DrawTexturePro(txhardsusp3, src3, dest3, origin3, 0.0f, WHITE);
            Rectangle sp3{ 440, 280, 100, 30 };
            if (GuiButton(sp3, hard_obj.get_suspects().at(2).get_name().get_cs()))
            {
                log.write_action("User chose suspect 3.");
                currentScreen = HARDSUSP3;
            }

            Rectangle src4 = { 0, 0, (float)txhardsusp4.width, (float)txhardsusp4.height };
            Rectangle dest4 = { 620, 150, 125, 125 };
            Vector2 origin4 = { 0, 0 };
            DrawTexturePro(txhardsusp4, src4, dest4, origin4, 0.0f, WHITE);
            Rectangle sp4{ 630, 280, 100, 30 };
            if (GuiButton(sp4, hard_obj.get_suspects().at(3).get_name().get_cs()))
            {
                log.write_action("User chose suspect 4.");
                currentScreen = HARDSUSP4;
            }

            Rectangle src5 = { 0, 0, (float)txhardsusp5.width, (float)txhardsusp5.height };
            Rectangle dest5 = { 50, 350, 125, 125 };
            Vector2 origin5 = { 0, 0 };
            DrawTexturePro(txhardsusp5, src5, dest5, origin5, 0.0f, WHITE);
            Rectangle sp5{ 60, 480, 100, 30 };
            if (GuiButton(sp5, hard_obj.get_suspects().at(4).get_name().get_cs()))
            {
                log.write_action("User chose suspect 5.");
                currentScreen = HARDSUSP5;
            }

            Rectangle src6 = { 0, 0, (float)txhardsusp6.width, (float)txhardsusp6.height };
            Rectangle dest6 = { 235, 350, 125, 125 };
            Vector2 origin6 = { 0, 0 };
            DrawTexturePro(txhardsusp6, src6, dest6, origin6, 0.0f, WHITE);
            Rectangle sp6{ 250, 480, 100, 30 };
            if (GuiButton(sp6, hard_obj.get_suspects().at(5).get_name().get_cs()))
            {
                log.write_action("User chose suspect 6.");
                currentScreen = HARDSUSP6;
            }

            Rectangle src7 = { 0, 0, (float)txhardsusp7.width, (float)txhardsusp7.height };
            Rectangle dest7 = { 420, 340, 140, 140 };
            Vector2 origin7 = { 0, 0 };
            DrawTexturePro(txhardsusp7, src7, dest7, origin7, 0.0f, WHITE);
            Rectangle sp7{ 440, 480, 100, 30 };
            if (GuiButton(sp7, hard_obj.get_suspects().at(6).get_name().get_cs()))
            {
                log.write_action("User chose suspect 7.");
                currentScreen = HARDSUSP7;
            }

            Rectangle src8 = { 0, 0, (float)txhardsusp8.width, (float)txhardsusp8.height };
            Rectangle dest8 = { 620, 350, 125, 125 };
            Vector2 origin8 = { 0, 0 };
            DrawTexturePro(txhardsusp8, src8, dest8, origin8, 0.0f, WHITE);
            Rectangle sp8{ 630, 480, 100, 30 };
            if (GuiButton(sp8, hard_obj.get_suspects().at(7).get_name().get_cs()))
            {
                log.write_action("User chose suspect 8.");
                currentScreen = HARDSUSP8;
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARD;
        }

        else if (currentScreen == HARDSUSP1)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(0);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp1.width, (float)txhardsusp1.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp1, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 1.");
                currentScreen = INTERHARD1;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP2)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(1);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp2.width, (float)txhardsusp2.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp2, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 2.");
                currentScreen = INTERHARD2;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP3)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(2);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp3.width, (float)txhardsusp3.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp3, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 3.");
                currentScreen = INTERHARD3;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP4)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(3);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp4.width, (float)txhardsusp4.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp4, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 4.");
                currentScreen = INTERHARD4;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP5)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(4);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp5.width, (float)txhardsusp5.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp5, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 5.");
                currentScreen = INTERHARD5;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP6)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(5);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp6.width, (float)txhardsusp6.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp6, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 6.");
                currentScreen = INTERHARD6;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP7)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(6);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txmedsusp5.width, (float)txmedsusp5.height };
            Rectangle dest = { 570, 100, 225, 225 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txmedsusp5, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 7.");
                currentScreen = INTERHARD7;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == HARDSUSP8)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);
            suspect temp_susp = hard_obj.get_suspects().at(7);

            DrawText("Name: ", 60, 100, 20, LIGHTGRAY);
            DrawText(temp_susp.get_name().get_cs(), 130, 100, 20, LIGHTGRAY);

            int temp_age = temp_susp.get_age();
            my_str age_str;
            age_str.itos(temp_age);

            DrawText("Age: ", 60, 150, 20, LIGHTGRAY);
            DrawText(age_str.get_cs(), 110, 150, 20, LIGHTGRAY);

            DrawText("Gender: ", 60, 200, 20, LIGHTGRAY);

            if (temp_susp.get_gender() == 'M')
                DrawText("Male", 140, 200, 20, LIGHTGRAY);
            else if (temp_susp.get_gender() == 'F')
                DrawText("Female", 140, 200, 20, LIGHTGRAY);

            DrawText("DOB: ", 60, 250, 20, LIGHTGRAY);
            my_str temp_d, temp_mon, temp_yr;
            temp_d.itos(temp_susp.get_dob().get_day());
            temp_mon.itos(temp_susp.get_dob().get_mon());
            temp_yr.itos(temp_susp.get_dob().get_yr());

            DrawText(temp_d.get_cs(), 110, 250, 20, LIGHTGRAY);
            DrawText("/", 135, 250, 20, LIGHTGRAY);
            DrawText(temp_mon.get_cs(), 150, 250, 20, LIGHTGRAY);
            DrawText("/", 170, 250, 20, LIGHTGRAY);
            DrawText(temp_yr.get_cs(), 190, 250, 20, LIGHTGRAY);
            DrawText("Occupation: ", 60, 300, 20, LIGHTGRAY);
            DrawText(temp_susp.get_occupation().get_cs(), 185, 300, 20, LIGHTGRAY);
            DrawText("Relation With Deceased: ", 60, 350, 20, LIGHTGRAY);
            DrawText(temp_susp.get_relation().get_cs(), 310, 350, 20, LIGHTGRAY);

            Rectangle src = { 0, 0, (float)txhardsusp8.width, (float)txhardsusp8.height };
            Rectangle dest = { 570, 100, 150, 200 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardsusp8, src, dest, origin, 0.0f, WHITE);

            if (GuiButton(btn_back_instructions, "Interrogation"))
            {
                log.write_action("User is interrogating suspect 8.");
                currentScreen = INTERHARD8;
            }

            if (GuiButton(right_back_btn, "Back"))
                currentScreen = VIEW_SUSPECT_HARD;
        }

        else if (currentScreen == INTERHARD1)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_hard1 = true;
            }

            if (statement_edit_hard1)
                DrawText(hard_obj.get_suspects().at(0).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);


            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_hard1 = true;
            if (location_edit_hard1)
                DrawText(hard_obj.get_suspects().at(0).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard1.itos(hard_obj.get_suspects().at(0).get_alibi().get_timing().get_hr());
                temp_min_hard1.itos(hard_obj.get_suspects().at(0).get_alibi().get_timing().get_min());
                temp_secs_hard1.itos(hard_obj.get_suspects().at(0).get_alibi().get_timing().get_secs());
                time_edit_hard1 = true;
            }

            if (time_edit_hard1)
            {
                DrawText(temp_hr_hard1.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard1.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard1.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_hard1 = true;
            }

            if (witness_edit_hard1)
                DrawText(hard_obj.get_suspects().at(0).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARDSUSP1;
        }

        else if (currentScreen == INTERHARD2)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:"))
            {
                statement_edit_hard2 = true;
            }

            if (statement_edit_hard2)
                DrawText(hard_obj.get_suspects().at(1).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_hard2 = true;
            if (location_edit_hard2)
                DrawText(hard_obj.get_suspects().at(1).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard2.itos(hard_obj.get_suspects().at(1).get_alibi().get_timing().get_hr());
                temp_min_hard2.itos(hard_obj.get_suspects().at(1).get_alibi().get_timing().get_min());
                temp_secs_hard2.itos(hard_obj.get_suspects().at(1).get_alibi().get_timing().get_secs());
                time_edit_hard2 = true;
            }

            if (time_edit_hard2)
            {
                DrawText(temp_hr_hard2.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard2.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard2.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:"))
            {
                witness_edit_hard2 = true;
            }

            if (witness_edit_hard2)
                DrawText(hard_obj.get_suspects().at(1).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARDSUSP2;
        }

        else if (currentScreen == INTERHARD3)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:")) statement_edit_hard3 = true;
            if (statement_edit_hard3)
                DrawText(hard_obj.get_suspects().at(2).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:")) location_edit_hard3 = true;
            if (location_edit_hard3)
                DrawText(hard_obj.get_suspects().at(2).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard3.itos(hard_obj.get_suspects().at(2).get_alibi().get_timing().get_hr());
                temp_min_hard3.itos(hard_obj.get_suspects().at(2).get_alibi().get_timing().get_min());
                temp_secs_hard3.itos(hard_obj.get_suspects().at(2).get_alibi().get_timing().get_secs());
                time_edit_hard3 = true;
            }
            if (time_edit_hard3)
            {
                DrawText(temp_hr_hard3.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard3.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard3.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:")) witness_edit_hard3 = true;
            if (witness_edit_hard3)
                DrawText(hard_obj.get_suspects().at(2).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back")) 
                currentScreen = HARDSUSP3;
        }

        else if (currentScreen == INTERHARD4)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:")) 
                statement_edit_hard4 = true;
            if (statement_edit_hard4)
                DrawText(hard_obj.get_suspects().at(3).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:"))
                location_edit_hard4 = true;
            if (location_edit_hard4)
                DrawText(hard_obj.get_suspects().at(3).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard4.itos(hard_obj.get_suspects().at(3).get_alibi().get_timing().get_hr());
                temp_min_hard4.itos(hard_obj.get_suspects().at(3).get_alibi().get_timing().get_min());
                temp_secs_hard4.itos(hard_obj.get_suspects().at(3).get_alibi().get_timing().get_secs());
                time_edit_hard4 = true;
            }
            if (time_edit_hard4)
            {
                DrawText(temp_hr_hard4.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard4.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard4.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:")) witness_edit_hard4 = true;
            if (witness_edit_hard4)
                DrawText(hard_obj.get_suspects().at(3).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARDSUSP4;
        }

        else if (currentScreen == INTERHARD5)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:")) statement_edit_hard5 = true;
            if (statement_edit_hard5)
                DrawText(hard_obj.get_suspects().at(4).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:")) location_edit_hard5 = true;
            if (location_edit_hard5)
                DrawText(hard_obj.get_suspects().at(4).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard5.itos(hard_obj.get_suspects().at(4).get_alibi().get_timing().get_hr());
                temp_min_hard5.itos(hard_obj.get_suspects().at(4).get_alibi().get_timing().get_min());
                temp_secs_hard5.itos(hard_obj.get_suspects().at(4).get_alibi().get_timing().get_secs());
                time_edit_hard5 = true;
            }
            if (time_edit_hard5)
            {
                DrawText(temp_hr_hard5.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard5.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard5.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:")) witness_edit_hard5 = true;
            if (witness_edit_hard5)
                DrawText(hard_obj.get_suspects().at(4).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARDSUSP5;
        }

        else if (currentScreen == INTERHARD6)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:")) statement_edit_hard6 = true;
            if (statement_edit_hard6)
                DrawText(hard_obj.get_suspects().at(5).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:")) location_edit_hard6 = true;
            if (location_edit_hard6)
                DrawText(hard_obj.get_suspects().at(5).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard6.itos(hard_obj.get_suspects().at(5).get_alibi().get_timing().get_hr());
                temp_min_hard6.itos(hard_obj.get_suspects().at(5).get_alibi().get_timing().get_min());
                temp_secs_hard6.itos(hard_obj.get_suspects().at(5).get_alibi().get_timing().get_secs());
                time_edit_hard6 = true;
            }
            if (time_edit_hard6)
            {
                DrawText(temp_hr_hard6.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard6.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard6.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:")) witness_edit_hard6 = true;
            if (witness_edit_hard6)
                DrawText(hard_obj.get_suspects().at(5).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back")) currentScreen = HARDSUSP6;
        }

        else if (currentScreen == INTERHARD7)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:")) statement_edit_hard7 = true;
            if (statement_edit_hard7)
                DrawText(hard_obj.get_suspects().at(6).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:")) location_edit_hard7 = true;
            if (location_edit_hard7)
                DrawText(hard_obj.get_suspects().at(6).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard7.itos(hard_obj.get_suspects().at(6).get_alibi().get_timing().get_hr());
                temp_min_hard7.itos(hard_obj.get_suspects().at(6).get_alibi().get_timing().get_min());
                temp_secs_hard7.itos(hard_obj.get_suspects().at(6).get_alibi().get_timing().get_secs());
                time_edit_hard7 = true;
            }
            if (time_edit_hard7)
            {
                DrawText(temp_hr_hard7.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard7.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard7.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:")) witness_edit_hard7 = true;
            if (witness_edit_hard7)
                DrawText(hard_obj.get_suspects().at(6).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back")) currentScreen = HARDSUSP7;
        }

        else if (currentScreen == INTERHARD8)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Suspects", 300, 20, 36, GOLD);

            Rectangle btn_state{ 100,100,100,100 };
            Rectangle btn_location{ 100, 180, 150, 40 };
            Rectangle btn_time{ 100,240,150,40 };
            Rectangle btn_witness{ 100,300,150,40 };

            if (GuiLabelButton(btn_state, "Statement:")) statement_edit_hard8 = true;
            if (statement_edit_hard8)
                DrawText(hard_obj.get_suspects().at(7).get_alibi().get_statement().get_cs(), 100, 170, 10, GRAY);

            if (GuiLabelButton(btn_location, "Location:")) location_edit_hard8 = true;
            if (location_edit_hard8)
                DrawText(hard_obj.get_suspects().at(7).get_alibi().get_location().get_cs(), 100, 220, 10, GRAY);

            if (GuiLabelButton(btn_time, "Time:"))
            {
                temp_hr_hard8.itos(hard_obj.get_suspects().at(7).get_alibi().get_timing().get_hr());
                temp_min_hard8.itos(hard_obj.get_suspects().at(7).get_alibi().get_timing().get_min());
                temp_secs_hard8.itos(hard_obj.get_suspects().at(7).get_alibi().get_timing().get_secs());
                time_edit_hard8 = true;
            }
            if (time_edit_hard8)
            {
                DrawText(temp_hr_hard8.get_cs(), 100, 280, 10, GRAY);
                DrawText(":", 110, 280, 10, GRAY);
                DrawText(temp_min_hard8.get_cs(), 120, 280, 10, GRAY);
                DrawText(":", 130, 280, 10, GRAY);
                DrawText(temp_secs_hard8.get_cs(), 140, 280, 10, GRAY);
            }

            if (GuiLabelButton(btn_witness, "Witness:")) witness_edit_hard8 = true;
            if (witness_edit_hard8)
                DrawText(hard_obj.get_suspects().at(7).get_alibi().get_witness().get_cs(), 100, 335, 10, GRAY);

            if (GuiButton(btn_back_instructions, "Back")) currentScreen = HARDSUSP8;
        }

        else if (currentScreen == SEARCH_ROOMS_HARD)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Rooms", 350, 20, 36, GOLD);
            DrawText("Select a room to investigate: ", 60, 100, 20, LIGHTGRAY);

            dynamic_array<room> temp_rooms = hard_obj.get_rooms();

            for (int i = 0; i < temp_rooms.size()/2; i++)
            {
                Rectangle roomBtn = { 150, 150 + i * 100, 220, 60 };

                if (GuiButton(roomBtn, temp_rooms.at(i).get_name().get_cs()))
                {
                    if (i == 0)
                    {
                        log.write_action("User is searching room 1.");
                        currentScreen = R1HARD;
                    }
                    else if (i == 1)
                    {
                        log.write_action("User is searching room 2.");
                        currentScreen = R2HARD;
                    }
                    else if (i == 2)
                    {
                        log.write_action("User is searching room 3.");
                        currentScreen = R3HARD;
                    }
                }
            }

            for (int i = temp_rooms.size() / 2; i <(temp_rooms.size())-1 ; i++)
            {
                Rectangle roomBtn = { 450, 150 + (i- temp_rooms.size() / 2) * 100, 220, 60 };

                if (GuiButton(roomBtn, temp_rooms.at(i).get_name().get_cs()))
                {
                    if (i == 3)
                    {
                        log.write_action("User is searching room 4.");
                        currentScreen = R4HARD;
                    }
                    else if (i == 4)
                    {
                        log.write_action("User is searching room 5.");
                        currentScreen = R5HARD;
                    }
                    else if (i == 5)
                    {
                        log.write_action("User is searching room 6.");
                        currentScreen = R6HARD;
                    }
                }
            }

            Rectangle roomBtn = { 300, 150 + (6 - temp_rooms.size() / 2) * 100, 220, 60 };
            if (GuiButton(roomBtn, temp_rooms.at(6).get_name().get_cs()))
            {
                log.write_action("User is searching room 7.");
                currentScreen = R7HARD;
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARD;
        }

        else if (currentScreen == R1HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr1.width, (float)txhardr1.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr1, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));
            DrawText("Study", 300, 20, 36, BROWN);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(0).get_objs();

            static bool object_clicked[5] = { false };
            static bool clue_revealed[5] = { false };
            static bool clue_write[5] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 80;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Room: Study\n";
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == R2HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr2.width, (float)txhardr2.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr2, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(hard_obj.get_rooms().at(1).get_name().get_cs(), 270, 20, 36,BLACK);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(1).get_objs();

            static bool object_clicked[4] = { false };
            static bool clue_revealed[4] = { false };
            static bool clue_write[4] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, BLACK);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == R3HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr3.width, (float)txhardr3.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr3, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(DARKBROWN, 0.6f));

            DrawText(hard_obj.get_rooms().at(2).get_name().get_cs(), 330, 20, 36, DARKBROWN);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(2).get_objs();

            static bool object_clicked[5] = { false };
            static bool clue_revealed[5] = { false };
            static bool clue_write[5] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 80;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == R4HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr4.width, (float)txhardr4.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr4, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(hard_obj.get_rooms().at(3).get_name().get_cs(), 330, 20, 36, BLACK);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(3).get_objs();

            static bool object_clicked[3] = { false };
            static bool clue_revealed[3] = { false };
            static bool clue_write[3] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 100;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == R5HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr5.width, (float)txhardr5.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr5, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(Color{ 25, 25, 35, 255 }, 0.6f));

            DrawText(hard_obj.get_rooms().at(4).get_name().get_cs(), 330, 30, 36, BLACK);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(4).get_objs();

            static bool object_clicked[4] = { false };
            static bool clue_revealed[4] = { false };
            static bool clue_write[4] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 90;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == R6HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr6.width, (float)txhardr6.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr6, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(hard_obj.get_rooms().at(5).get_name().get_cs(), 300, 20, 36, BLACK);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(5).get_objs();

            static bool object_clicked[4] = { false };
            static bool clue_revealed[4] = { false };
            static bool clue_write[4] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 90;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, BLACK);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == R7HARD)
        {
            Rectangle src = { 0, 0, (float)txhardr7.width, (float)txhardr7.height };
            Rectangle dest = { 0, 0, 800, 600 };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(txhardr7, src, dest, origin, 0.0f, WHITE);
            DrawRectangle(30, 70, 750, 500, Fade(BROWN, 0.6f));

            DrawText(hard_obj.get_rooms().at(6).get_name().get_cs(), 330, 20, 36, BEIGE);
            dynamic_array<game_obj> t_objs = hard_obj.get_rooms().at(6).get_objs();

            static bool object_clicked[5] = { false };
            static bool clue_revealed[5] = { false };
            static bool clue_write[5] = { false };

            for (int i = 0; i < t_objs.size(); i++)
            {
                int y = 100 + i * 80;
                Rectangle objBtn = { 45, y, 150, 40 };
                Rectangle clueBtn = { 225, y, 150, 40 };

                if (GuiButton(objBtn, t_objs.at(i).get_name().get_cs()))
                    object_clicked[i] = true;

                if (object_clicked[i] && t_objs.at(i).get_contains_cl())
                {
                    if (GuiButton(clueBtn, "Reveal Clue"))
                        clue_revealed[i] = true;

                    if (clue_revealed[i])
                    {
                        DrawText(t_objs.at(i).get_clue().at(0).get_descr().get_cs(), 400, y + 10, 10, LIGHTGRAY);
                        if (!clue_write[i])
                        {
                            ofstream fout("hard_evidence.txt", ios::app);
                            if (fout.is_open())
                            {
                                fout << "Object: " << t_objs.at(i).get_name().get_cs() << "\n";
                                fout << "Clue: " << t_objs.at(i).get_clue().at(0).get_descr().get_cs() << "\n\n";
                                fout.close();
                                clue_write[i] = true;
                            }
                        }
                    }
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = SEARCH_ROOMS_HARD;
        }

        else if (currentScreen == VIEW_EVIDENCE_HARD)
        {
            DrawText("Evidences", 300, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.6f));

            ifstream fin("hard_evidence.txt");
            if (fin.is_open())
            {
                char arr[300];
                int y = 80;

                while (fin.getline(arr, 300))
                {
                    my_str line(arr);
                    if (line.get_length() > 0)
                    {
                        DrawText(line.get_cs(), 50, y, 15, LIGHTGRAY);
                        y = y + 20;
                    }
                }

                fin.close();
            }

            else
            {
                DrawText("No evidence found.", 50, 80, 20, RED);
            }

            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = HARD;
        }

        else if (currentScreen == MAKING_ACCUSATION_HARD)
        {
            static int selected = -1;
            static bool confirmation = false;

            DrawText("Suspects", 300, 20, 36, GOLD);
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawText("Select the suspect for further investigation", 60, 100, 20, LIGHTGRAY);

            Rectangle src1 = { 0, 0, (float)txhardsusp1.width, (float)txhardsusp1.height };
            Rectangle dest1 = { 50, 150, 125, 125 };
            Vector2 origin1 = { 0, 0 };
            DrawTexturePro(txhardsusp1, src1, dest1, origin1, 0.0f, WHITE);
            Rectangle sp1{ 60, 280, 100, 30 };
            if (GuiButton(sp1, hard_obj.get_suspects().at(0).get_name().get_cs()))
            {
                selected = 0;
                confirmation = true;
            }

            Rectangle src2 = { 0, 0, (float)txhardsusp2.width, (float)txhardsusp2.height };
            Rectangle dest2 = { 235, 150, 120, 120 };
            Vector2 origin2 = { 0, 0 };
            DrawTexturePro(txhardsusp2, src2, dest2, origin2, 0.0f, WHITE);
            Rectangle sp2{ 250, 280, 100, 30 };
            if (GuiButton(sp2, hard_obj.get_suspects().at(1).get_name().get_cs()))
            {
                selected = 1;
                confirmation = true;
            }

            Rectangle src3 = { 0, 0, (float)txhardsusp3.width, (float)txhardsusp3.height };
            Rectangle dest3 = { 430, 150, 120, 120 };
            Vector2 origin3 = { 0, 0 };
            DrawTexturePro(txhardsusp3, src3, dest3, origin3, 0.0f, WHITE);
            Rectangle sp3{ 440, 280, 100, 30 };
            if (GuiButton(sp3, hard_obj.get_suspects().at(2).get_name().get_cs()))
            {
                selected = 2;
                confirmation = true;
            }

            Rectangle src4 = { 0, 0, (float)txhardsusp4.width, (float)txhardsusp4.height };
            Rectangle dest4 = { 620, 150, 125, 125 };
            Vector2 origin4 = { 0, 0 };
            DrawTexturePro(txhardsusp4, src4, dest4, origin4, 0.0f, WHITE);
            Rectangle sp4{ 630, 280, 100, 30 };
            if (GuiButton(sp4, hard_obj.get_suspects().at(3).get_name().get_cs()))
            {
                selected = 3;
                confirmation = true;
            }

            Rectangle src5 = { 0, 0, (float)txhardsusp5.width, (float)txhardsusp5.height };
            Rectangle dest5 = { 50, 350, 125, 125 };
            Vector2 origin5 = { 0, 0 };
            DrawTexturePro(txhardsusp5, src5, dest5, origin5, 0.0f, WHITE);
            Rectangle sp5{ 60, 480, 100, 30 };
            if (GuiButton(sp5, hard_obj.get_suspects().at(4).get_name().get_cs()))
            {
                selected = 4;
                confirmation = true;
            }

            Rectangle src6 = { 0, 0, (float)txhardsusp6.width, (float)txhardsusp6.height };
            Rectangle dest6 = { 235, 350, 125, 125 };
            Vector2 origin6 = { 0, 0 };
            DrawTexturePro(txhardsusp6, src6, dest6, origin6, 0.0f, WHITE);
            Rectangle sp6{ 250, 480, 100, 30 };
            if (GuiButton(sp6, hard_obj.get_suspects().at(5).get_name().get_cs()))
            {
                selected = 5;
                confirmation = true;
            }

            Rectangle src7 = { 0, 0, (float)txhardsusp7.width, (float)txhardsusp7.height };
            Rectangle dest7 = { 420, 340, 140, 140 };
            Vector2 origin7 = { 0, 0 };
            DrawTexturePro(txhardsusp7, src7, dest7, origin7, 0.0f, WHITE);
            Rectangle sp7{ 440, 480, 100, 30 };
            if (GuiButton(sp7, hard_obj.get_suspects().at(6).get_name().get_cs()))
            {
                selected = 6;
                confirmation = true;
            }

            Rectangle src8 = { 0, 0, (float)txhardsusp8.width, (float)txhardsusp8.height };
            Rectangle dest8 = { 620, 350, 125, 125 };
            Vector2 origin8 = { 0, 0 };
            DrawTexturePro(txhardsusp8, src8, dest8, origin8, 0.0f, WHITE);
            Rectangle sp8{ 630, 480, 100, 30 };
            if (GuiButton(sp8, hard_obj.get_suspects().at(7).get_name().get_cs()))
            {
                selected = 7;
                confirmation = true;
            }

            if (confirmation && selected != -1)
            {
                DrawRectangle(225, 125, 350, 350, Fade(BLACK, 0.8f));
                Rectangle sure{ 250, 320, 130, 40 };
                Rectangle cancel{ 420, 320, 130, 40 };
                DrawText("Are you sure?", 320, 230, 24, GOLD);
                if (GuiButton(sure, "Yes, I am sure"))
                {
                    log.write_action("User made an accusation.");
                    if (hard_obj.get_suspects().at(selected).get_is_killer())
                    {
                        log.write_action("User won.");
                        currentScreen = HARD_WIN;
                    }
                    else
                    {
                        log.write_action("User lost.");
                        currentScreen = HARD_LOSE;
                    }

                    selected = -1;
                    confirmation = false;
                }

                if (GuiButton(cancel, "Cancel"))
                {
                    selected = -1;
                    confirmation = false;
                }
            }

            if (GuiButton(btn_back_instructions, "Back"))
            {
                currentScreen = HARD;
                selected = -1;
                confirmation = false;
            }
        }

        else if (currentScreen == HARD_WIN)
        {
            int susp_num = hard_obj.get_suspects().size();
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            my_str temp_name;
            DrawText("YOU WON!", 250, 150, 60, GREEN);
            int count = 0;

            for (int i = 0;i < susp_num;i++)
            {
                if (hard_obj.get_suspects().at(i).get_is_killer())
                {
                    count++;
                    temp_name = hard_obj.get_suspects().at(i).get_name();
                    break;
                }
            }

            DrawText(temp_name.get_cs(), 205, 250, 30, RAYWHITE);
            DrawText("is the killer!", 420, 250, 30, RAYWHITE);

            if (GuiButton(btn_back_instructions, "Exit"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == HARD_LOSE)
        {
            int susp_num = hard_obj.get_suspects().size();
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            my_str temp_name;
            DrawText("YOU LOSE!", 250, 150, 60, RED);
            int count = 0;

            for (int i = 0;i < susp_num;i++)
            {
                if (hard_obj.get_suspects().at(i).get_is_killer())
                {
                    count++;
                    temp_name = hard_obj.get_suspects().at(i).get_name();
                    break;
                }
            }

            DrawText(temp_name.get_cs(), 205, 250, 30, RAYWHITE);
            DrawText("is the killer!", 420, 250, 30, RAYWHITE);

            if (GuiButton(btn_back_instructions, "Exit"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == INSTRUCTIONS)
        {
            DrawRectangle(30, 70, 750, 500, Fade(BLACK, 0.5f));
            DrawInstructionsScreen();
            if (GuiButton(btn_back_instructions, "Back"))
                currentScreen = MAIN_MENU;
        }

        else if (currentScreen == EXIT)
        {
            break;
        }

        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
    
}