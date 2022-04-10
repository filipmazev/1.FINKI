#include<iostream>
#include<cstring>

class Category
{
private:
    char *name = "unnamed";
public:
    Category(){}
    Category(char *name){ this->name = new char[strlen(name)+1]; strcpy(this->name,name); }
    ~Category(){}

    void print(){ std::cout<<"Category: "<<this->name<<std::endl; }
};

class NewsArticle
{
private:
    Category c; char *title = "untitled";
public:
    NewsArticle(){}
    NewsArticle(Category c, char *title){ this->title = new char[strlen(title)+1]; strcpy(this->title,title); this->c=c; }
    NewsArticle(Category c){ this->c = c; }
    ~NewsArticle(){}

    Category getC(){ return this->c; }
    void print(){ std::cout<<"Article title: "<<this->title<<std::endl; }
};

class FrontPage
{
private:
    NewsArticle n_a; float price=0; int editionNumber=0;
public:
    FrontPage(){}
    FrontPage(NewsArticle n_a, float price, int editionNumber){ this->n_a=n_a; this->price=price; this->editionNumber=editionNumber; }
    FrontPage(NewsArticle n_a, float price){ this->n_a=n_a; this->price=price; }
    ~FrontPage(){}

    void print(){ std::cout<<"Price: "<<this->price<<", Edition number: "<<this->editionNumber<<std::endl; n_a.print(); n_a.getC().print(); }
};

int main()
{
	char categoryName[20], articleTitle[30]; float price; int editionNumber, testCase, iter; std::cin>>testCase;

	if (testCase == 1)
    {
		std::cin>>iter;

		while (iter > 0)
        {
            std::cin>>categoryName>>articleTitle>>price>>editionNumber;
            Category category(categoryName); NewsArticle article(category, articleTitle);
            FrontPage frontPage(article, price, editionNumber); frontPage.print(); iter--;
        }
	}

	else if (testCase == 2)
    {
		std::cin>>categoryName>>price>>editionNumber;
		Category category(categoryName); NewsArticle article(category);
		FrontPage frontPage(article, price, editionNumber); frontPage.print();
	}

	else if (testCase == 3)
    {
		std::cin>>categoryName>>articleTitle>>price;
		Category category(categoryName); NewsArticle article(category, articleTitle);
		FrontPage frontPage(article, price); frontPage.print();
	}

    else  { FrontPage frontPage = FrontPage(); frontPage.print(); }

	return 0;
}
