#include "task3.h"
#include "Matrix.h"
#include "Record.h"
#include<bits/stdc++.h>

using namespace std;

    task3::task3(Matrix M){
        mat = M;
        int Columns = mat.getNoCols();
        int Rows = mat.getNoRows();
    }
    vector<double> getColumn(int c){
        vector<double> Column;
        for(int i=0; i<mat.getNoRows(); i++)
        {
            Column.push_back(mat[i][c]);
        }
        return Column;
    }
    vector<double>task3:: AutoCorrelation_Values_for_filtered_variables(){
        vector<double > Array_of_autoCorrelation_values;
        vector<double > filteredColumns;
        for(int j=0; j<Columns; j++)
        {
            double x = AutoCorr_Computation(getColumn(j));
            if(x<=-0.5 || x>=0.5) {
                Array_of_autoCorrelation_values.push_back(x);
            }
        }
        return Array_of_autoCorrelation_values;
    }
    vector<double>task3::Filtered_Variables() {
        vector<double > filteredColumns;
        for(int i=0; i<Columns; i++){
            double x = AutoCorr_Computation(getColumn(i));
            if(x<=-0.5 || x>=0.5) {
                filteredColumns.push_back(i);
            }
        }
        return filteredColumns;
    }



    int task3::Num_Of_Filtered_Variables()  {
        int count=0;
        for(int i=0; i<Columns; i++){
            double x = AutoCorr_Computation(getColumn(i));
            if(x<=-0.5 || x>=0.5) {
                count++;
            }
        }
        return count;
    }



    double task3::correlation_Coefficient(vector<double> X,vector <double> Y)
    {

        double sum_X = 0, sum_Y = 0, sum_XY = 0;
        double squareSum_X = 0, squareSum_Y = 0;

        for (int i = 0; i < Rows; i++)
        {
            // sum of elements of array X.
            sum_X = sum_X + X[i];
            // sum of elements of array Y.
            sum_Y = sum_Y + Y[i];

            // sum of X[i] * Y[i].
            sum_XY = sum_XY + X[i] * Y[i];

            // sum of square of array elements.
            squareSum_X = squareSum_X + X[i] * X[i];
            squareSum_Y = squareSum_Y + Y[i] * Y[i];
        }

        // use formula for calculating correlation coefficient.
        double corr = (double)(Rows * sum_XY - sum_X * sum_Y)
                      / sqrt((Rows * squareSum_X - sum_X * sum_X)
                             * (Rows * squareSum_Y - sum_Y * sum_Y));

        return corr;
    }



    double task3::AutoCorr_Computation(vector<double>X) {
        double x = correlation_Coefficient(X,X);
        return x;
    }


    vector<double> task3::Sorting_Variables_based_on_autoco() {
        vector<double > Sorted;
        for (int i = 0; i < Num_Of_Filtered_Variables(); i++) {
            Sorted=sort(AutoCorrelation_Values_for_filtered_variables().begin(),AutoCorrelation_Values_for_filtered_variables().end);
        }
        return Sorted;
    }


    Matrix task3::CorrelationMatrix() {
        Matrix MATRIX = new Matrix(Num_Of_Filtered_Variables(),Num_Of_Filtered_Variables());
        for(int i=0; i<Num_Of_Filtered_Variables(); i++)
        {
            for (int j = 0; j < Num_Of_Filtered_Variables(); j++) {

                    MATRIX[i][j] = correlation_Coefficient(Filtered_Variables()[i],Filtered_Variables()[j]);
            }
        }
    }

#include "task3.h"
#include "Matrix.h"
#include "Record.h"
#include<bits/stdc++.h>

using namespace std;

    task3::task3(Matrix M){
        mat = M;
        int Columns = mat.getNoCols();
        int Rows = mat.getNoRows();
    }
    vector<double> getColumn(int c){
        vector<double> Column;
        for(int i=0; i<mat.getNoRows(); i++)
        {
            Column.push_back(mat[i][c]);
        }
        return Column;
    }
    vector<double>task3:: AutoCorrelation_Values_for_filtered_variables(){
        vector<double > Array_of_autoCorrelation_values;
        vector<double > filteredColumns;
        for(int j=0; j<Columns; j++)
        {
            double x = AutoCorr_Computation(getColumn(j));
            if(x<=-0.5 || x>=0.5) {
                Array_of_autoCorrelation_values.push_back(x);
            }
        }
        return Array_of_autoCorrelation_values;
    }
    vector<double>task3::Filtered_Variables() {
        vector<double > filteredColumns;
        for(int i=0; i<Columns; i++){
            double x = AutoCorr_Computation(getColumn(i));
            if(x<=-0.5 || x>=0.5) {
                filteredColumns.push_back(i);
            }
        }
        return filteredColumns;
    }



    int task3::Num_Of_Filtered_Variables()  {
        int count=0;
        for(int i=0; i<Columns; i++){
            double x = AutoCorr_Computation(getColumn(i));
            if(x<=-0.5 || x>=0.5) {
                count++;
            }
        }
        return count;
    }



    double task3::correlation_Coefficient(vector<double> X,vector <double> Y)
    {

        double sum_X = 0, sum_Y = 0, sum_XY = 0;
        double squareSum_X = 0, squareSum_Y = 0;

        for (int i = 0; i < Rows; i++)
        {
            // sum of elements of array X.
            sum_X = sum_X + X[i];
            // sum of elements of array Y.
            sum_Y = sum_Y + Y[i];

            // sum of X[i] * Y[i].
            sum_XY = sum_XY + X[i] * Y[i];

            // sum of square of array elements.
            squareSum_X = squareSum_X + X[i] * X[i];
            squareSum_Y = squareSum_Y + Y[i] * Y[i];
        }

        // use formula for calculating correlation coefficient.
        double corr = (double)(Rows * sum_XY - sum_X * sum_Y)
                      / sqrt((Rows * squareSum_X - sum_X * sum_X)
                             * (Rows * squareSum_Y - sum_Y * sum_Y));

        return corr;
    }



    double task3::AutoCorr_Computation(vector<double>X) {
        double x = correlation_Coefficient(X,X);
        return x;
    }


    vector<double> task3::Sorting_Variables_based_on_autoco() {
        vector<double > Sorted;
        for (int i = 0; i < Num_Of_Filtered_Variables(); i++) {
            Sorted=sort(AutoCorrelation_Values_for_filtered_variables().begin(),AutoCorrelation_Values_for_filtered_variables().end);
        }
        return Sorted;
    }


    Matrix task3::CorrelationMatrix() {
        Matrix MATRIX = new Matrix(Num_Of_Filtered_Variables(),Num_Of_Filtered_Variables());
        for(int i=0; i<Num_Of_Filtered_Variables(); i++)
        {
            for (int j = 0; j < Num_Of_Filtered_Variables(); j++) {

                    MATRIX[i][j] = correlation_Coefficient(Filtered_Variables()[i],Filtered_Variables()[j]);
            }
        }
    }


