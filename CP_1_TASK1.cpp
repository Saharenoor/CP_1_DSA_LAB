/*1)	Design an online exam portal system where:
The system stores a set of questions (question text, 4 options, correct answer index).
It randomly selects 5 out of 10 questions to display to the student.
The student answers questions one by one.
At the end, the system shows the score and percentage.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Question {
    string text;
    string options[4];
    int correctIndex;
};

void displayQuestion(Question& q, int qNumber) {
    cout << "Question " << qNumber << ": " << q.text << "\n";
    for (int i = 0; i < 4; ++i) {
        cout << char('A' + i) << ") " << q.options[i] << "\n";
    }
    cout << "Your answer (A-D): ";
}

void shuffleIndices(int arr[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int totalQuestions = 10;
    const int selectedQuestions = 5;

    Question questions[totalQuestions] = {
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Bear"}, 1},
        {"Which language is used to write Android apps?", {"Python", "C#", "Kotlin", "Swift"}, 2},
        {"How many continents are there?", {"5", "6", "7", "8"}, 2},
{"What is the powerhouse of the cell?", {"Nucleus", "Ribosome", "Mitochondria", "Chloroplast"}, 2},
{"Which desert is the largest in the world?", {"Sahara", "Gobi", "Kalahari", "Antarctic"}, 3},
{"In which year did World War II end?", {"1942", "1945", "1939", "1950"}, 1},
{"What is the main gas found in the Earth's atmosphere?", {"Oxygen", "Hydrogen", "Carbon Dioxide", "Nitrogen"}, 3},
{"Which ancient civilization built the Machu Picchu?", {"Maya", "Inca", "Aztec", "Olmec"}, 1},
{"Who proposed the theory of general relativity?", {"Isaac Newton", "Galileo Galilei", "Nikola Tesla", "Albert Einstein"}, 3}
    };

    int indices[totalQuestions];
    for (int i = 0; i < totalQuestions; ++i)
        indices[i] = i;

    shuffleIndices(indices, totalQuestions);

    int score = 0;

    for (int i = 0; i < selectedQuestions; ++i) {
        int qIndex = indices[i];
        displayQuestion(questions[qIndex], i + 1);
    
        char answer;
        while (true) {
            cin >> answer;
            answer = toupper(answer);
    
            if (answer >= 'A' && answer <= 'D') {
                break;
            } else {
                cout << "Invalid input! Please enter A, B, C, or D: ";
            }
        }
    
        int userIndex = answer - 'A';
        if (userIndex == questions[qIndex].correctIndex) {
            cout << "Correct!\n\n";
            score++;
        } else {
            cout << "Wrong! Correct answer: "
                 << char('A' + questions[qIndex].correctIndex) << "\n\n";
        }
    }

    cout << "Exam Finished!\n";
    cout << "Your Score: " << score << "/" << selectedQuestions << "\n";
    cout << "Percentage: " << (score * 100 / selectedQuestions) << "%\n";

    return 0;
}
