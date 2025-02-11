// Author: Yassine "LostSideDead" Fejrit
// Project: FitCalc 
// License: GNU GENERAL PUBLIC LICENSE
// Copyright (c) 2025 lostsidedead
  

#include <iostream>
#include <string>

using namespace std;

// Function to calculate BMR
double calculateBMR(int age, double weight, double height, char gender) {
    double BMR;

    if (gender == 'M' || gender == 'm') {
        // Harris-Benedict formula for men
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else if (gender == 'F' || gender == 'f') {
        // Harris-Benedict formula for women
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    } else {
        cout << "Invalid gender input" << endl;
        return 0;
    }
    
    return BMR;
}

// Function to calculate TDEE based on activity level
double calculateTDEE(double BMR, int activityLevel) {
    double TDEE;

    switch (activityLevel) {
        case 1: // Sedentary
            TDEE = BMR * 1.2;
            break;
        case 2: // Lightly active
            TDEE = BMR * 1.375;
            break;
        case 3: // Moderately active
            TDEE = BMR * 1.55;
            break;
        case 4: // Very active
            TDEE = BMR * 1.725;
            break;
        case 5: // Super active
            TDEE = BMR * 1.9;
            break;
        default:
            cout << "Invalid activity level" << endl;
            return 0;
    }

    return TDEE;
}

// Function to calculate protein requirements based on body weight
double calculateProtein(double weight) {
    // Assuming moderate activity, between 1.6 to 2.2g per kg
    return weight * 2.0;  // You can adjust this as per the activity level
}

int main() {
    int age;
    double weight, height;
    char gender;
    int activityLevel;

    cout << "Fitness Calculator" << endl;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your weight (kg): ";
    cin >> weight;
    cout << "Enter your height (cm): ";
    cin >> height;
    cout << "Enter your gender (M/F): ";
    cin >> gender;
    
    cout << "Enter your activity level (1: Sedentary, 2: Lightly active, 3: Moderately active, 4: Very active, 5: Super active): ";
    cin >> activityLevel;

    // Calculate BMR
    double BMR = calculateBMR(age, weight, height, gender);

    if (BMR == 0) return 0;

    // Calculate TDEE
    double TDEE = calculateTDEE(BMR, activityLevel);

    // Calculate protein requirement
    double protein = calculateProtein(weight);

    // Output the results
    cout << "\nYour BMR (Basal Metabolic Rate) is: " << BMR << " kcal/day" << endl;
    cout << "Your Total Daily Energy Expenditure (TDEE) is: " << TDEE << " kcal/day" << endl;
    cout << "Your recommended daily protein intake is: " << protein << " grams" << endl;

    return 0;
}
