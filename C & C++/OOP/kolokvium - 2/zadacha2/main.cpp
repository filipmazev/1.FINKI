#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

constexpr auto default_arr_size = 100;

enum class ERROR { NO_ERROR, INVALID_INPUT, SIZE_MISSMATCH};

class InvalidInput{
public:
    void print(){ std::cout<<"Invalid Input"<<endl; }
};

class SizeMissMatch{
public:
    void print(){ std::cout<<"Labels must have the same length"; }
};

class Evaluator{
protected:
    char* real = new char[default_arr_size];
    char* predicted = new char[default_arr_size];
public:
    Evaluator(){}

    Evaluator(char* real, char* predicted){
        try{
            for(int i=0; i<strlen(real); i++){ if(real[i] != '+' && real[i] != '-'){ throw(ERROR::INVALID_INPUT); } }
            for(int i=0; i<strlen(predicted); i++){ if(predicted[i] != '+'  && predicted[i] != '-'){ throw(ERROR::INVALID_INPUT); } }
            throw(ERROR::NO_ERROR);
        }
        catch(ERROR CODE){
            if(CODE == ERROR::INVALID_INPUT){ InvalidInput error; error.print(); }
            else if(CODE == ERROR::NO_ERROR){
                this->real = new char[strlen(real)+1]; strcpy(this->real, real);
                this->predicted = new char[strlen(predicted)+1]; strcpy(this->predicted, predicted);
            }
        }
    }

    char* getReal(){ return this->real; }
    char* getPredicted(){ return this->predicted; }

    ~Evaluator(){}

    virtual double evaluate () = 0;
    virtual void print () = 0;
};

class AccuracyEvaluator : public Evaluator{
private:
public:
    AccuracyEvaluator(){}
    AccuracyEvaluator(char* real, char* predicted) : Evaluator(real, predicted){
    };

    ~AccuracyEvaluator(){}

    double evaluate(){
        double cnt = 0;
        for(int i=0; i<strlen(this->real); i++){
            if(this->real[i] == this->predicted[i]){ cnt++; }
        }
        return cnt / strlen(this->real);
    }

    void print(){
        std::cout<<"Number of data points: "<<strlen(this->real)<<" Prediction Accuracy: "<<this->evaluate()<<std::endl;
    }
};

class SensitivityEvaluator : public Evaluator{
private:
public:
    SensitivityEvaluator(){}
    SensitivityEvaluator(char* real, char* predicted) : Evaluator(real, predicted){
    };

    ~SensitivityEvaluator(){}

    double evaluate(){
        double cnt = 0, cnt_p = 0;
        for(int i=0; i<strlen(this->real); i++){
            if(this->real[i] == '+'){
                cnt_p++; if(this->real[i] == this->predicted[i]){ cnt++; }
            }
        }
        return cnt / cnt_p;
    }

    void print(){
        std::cout<<"Number of data points: "<<strlen(this->real)<<" Prediction Sensitivity: "<<this->evaluate()<<std::endl;
    }
};

bool operator >= (Evaluator& cmp_1, Evaluator& cmp_2)
{
    return (cmp_1.evaluate() >= cmp_2.evaluate());
}

Evaluator * highestScore (Evaluator ** evaluators, int n){

    Evaluator* best;

    if(dynamic_cast<AccuracyEvaluator*>(evaluators[0]) != NULL){
        best = new AccuracyEvaluator(evaluators[0]->getReal(), evaluators[0]->getPredicted());
    }
    else if(dynamic_cast<SensitivityEvaluator*>(evaluators[0]) != NULL){
        best = new SensitivityEvaluator(evaluators[0]->getReal(), evaluators[0]->getPredicted());
    }

        for(int i=0; i<n; i++){
            if( evaluators[i]->evaluate() >= best->evaluate()){

                if(dynamic_cast<AccuracyEvaluator*>(evaluators[i]) != NULL){
                    best = new AccuracyEvaluator(evaluators[i]->getReal(), evaluators[i]->getPredicted());
                }
                else if(dynamic_cast<SensitivityEvaluator*>(evaluators[i]) != NULL){
                    best = new SensitivityEvaluator(evaluators[i]->getReal(), evaluators[i]->getPredicted());
                }
            }
        }
    return best;
}

int main()
{
    int testCase;
    char trueLabels[100];
    char predictedLabels[100];
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try{
            if(strlen(trueLabels) != strlen(predictedLabels)){ throw(ERROR::SIZE_MISSMATCH); }
            throw(ERROR::NO_ERROR);
        }
        catch(ERROR CODE){
            if(CODE == ERROR::SIZE_MISSMATCH){ SizeMissMatch error; error.print(); }
            else if(CODE == ERROR::NO_ERROR){
                Evaluator *evaluator = new AccuracyEvaluator(trueLabels, predictedLabels);
                cout << evaluator->evaluate() << endl;
                evaluator->print();
            }
        }
    }

    else if (testCase == 2)
    {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try{
            if(strlen(trueLabels) != strlen(predictedLabels)){ throw(ERROR::SIZE_MISSMATCH); }
            throw(ERROR::NO_ERROR);
        }
        catch(ERROR CODE){
            if(CODE == ERROR::SIZE_MISSMATCH){ SizeMissMatch error; error.print(); }
            else if(CODE == ERROR::NO_ERROR){
                Evaluator *evaluator = new SensitivityEvaluator(trueLabels, predictedLabels);
                cout << evaluator->evaluate() << endl;
                evaluator->print();
            }
        }
    }

    else if (testCase == 3)
    {
        cout << "TESTING CREATION OF BOTH EVALUATORS. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try{
            if(strlen(trueLabels) != strlen(predictedLabels)){ throw(ERROR::SIZE_MISSMATCH); }
            throw(ERROR::NO_ERROR);
        }
        catch(ERROR CODE){
            if(CODE == ERROR::SIZE_MISSMATCH){ SizeMissMatch error; error.print(); }
            else if(CODE == ERROR::NO_ERROR){
                Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
                Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
                accuracy->print();
                sensitivity->print();
            }
        }
    }

    else if (testCase == 4)
    {
        cout << "TESTING OPERATOR >=" << endl;
        cin >> trueLabels >> predictedLabels;


        try{
            if(strlen(trueLabels) != strlen(predictedLabels)){ throw(ERROR::SIZE_MISSMATCH); }
            throw(ERROR::NO_ERROR);
        }
        catch(ERROR CODE){
            if(CODE == ERROR::SIZE_MISSMATCH){ SizeMissMatch error; error.print(); }
            else if(CODE == ERROR::NO_ERROR){
                Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
                Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);

                cin >> trueLabels >> predictedLabels;

                try{
                    if(strlen(trueLabels) != strlen(predictedLabels)){ throw(ERROR::SIZE_MISSMATCH); }
                    throw(ERROR::NO_ERROR);
                }
                catch(ERROR CODE){
                    if(CODE == ERROR::SIZE_MISSMATCH){ SizeMissMatch error; error.print(); }
                    else if(CODE == ERROR::NO_ERROR){
                        Evaluator *accuracy1 = new AccuracyEvaluator(trueLabels, predictedLabels);
                        Evaluator *sensitivity1 = new SensitivityEvaluator(trueLabels, predictedLabels);

                        accuracy->print();
                        cout << (((*accuracy) >= (*sensitivity)) ? ">=" : "<") << endl;
                        sensitivity->print();
                        cout << endl;

                        sensitivity->print();
                        cout << (((*sensitivity) >= (*accuracy)) ? ">=" : "<") << endl;
                        accuracy->print();
                        cout << endl;

                        accuracy->print();
                        cout << (((*accuracy) >= (*accuracy1)) ? ">=" : "<") << endl;
                        accuracy1->print();
                        cout << endl;

                        sensitivity->print();
                        cout << (((*sensitivity) >= (*sensitivity1)) ? ">=" : "<") << endl;
                        sensitivity1->print();
                        cout << endl;
                    }
                }
            }
        }
    }

    else
    {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION. EXCEPTION CAN HAPPEN HERE!" << endl;
        int n;
        cin >> n;
        Evaluator **evaluators = new Evaluator *[n];
        for (int i = 0; i < n; i++)
        {
            int type;
            cin >> type;
            cin >> trueLabels >> predictedLabels;

            try{ if(strlen(trueLabels) != strlen(predictedLabels)){ throw(ERROR::SIZE_MISSMATCH); } }

            catch(ERROR CODE){
                if(CODE == ERROR::SIZE_MISSMATCH){ SizeMissMatch error; error.print(); }
            }

            if (type == 1) //accuracy
            {
                evaluators[i] = new AccuracyEvaluator(trueLabels, predictedLabels);
            }

            else //sensitivity
            {
                evaluators[i] = new SensitivityEvaluator(trueLabels, predictedLabels);
            }

        }

        cout << "PRINT ALL EVALUATORS FIRST!" << endl;
        for (int i = 0; i < n; i++)
        {
           if(strlen(evaluators[i]->getReal()) == strlen(evaluators[i]->getPredicted())) { evaluators[i]->print(); }
        }

        cout << "RESULT FROM HIGHEST SCORE METHOD" << endl;
        highestScore(evaluators, n)->print();
    }

    return 0;
}
