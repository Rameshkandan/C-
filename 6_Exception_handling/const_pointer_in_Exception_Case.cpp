#include<iostream>
#include<memory>
#include<string>
class Book
{

};
class Image
{
	//void* operator new(size_t size){}
};
class Audio
{

};

class catalogue
{
public:
	catalogue(const std::string& N, const std::string& Add, const std::string& Imfile = " ", const std::string& Aufile = " ")
		:Name(N), Address(Add),Theimage(fun_image(Imfile)), Theaudio(fun_audio(Imfile))
		//Theimage((Imfile!=" ")? new Image: 0), Theaudio((Aufile != " ") ? new Audio : 0) 
		// initializing it to null pointer 
	// const ptrs with some bracnhing checking conditions have to be done with conditional operator
	// *** VERY IMPORTANT***
	{}

	~catalogue()
	{
		cleanup();
		std::cout << "\n\ndestructor called";
	}
private:
	std::string Name;
	std::string Address;
	Image * const Theimage;
	Audio * const Theaudio;
	//const unique_ptr<Image> Theimage;
	//const unique_ptr<Audio> Theaudio;
	void cleanup()
	{
		delete Theimage;
		std::cout << "\nImage object is deleted";
		delete Theaudio;
		std::cout << "\nAudio object is deleted";
	}
	Audio* fun_audio(const std::string& Aufile = " ")
	{
		try
		{
			if (Aufile != " ")
			{
				return new Audio;
				std::cout << "\n Audio object is created";
			}
			else
				return 0;
		}
		catch (...)
		{
		//delete Theimage; // catches all exceptions.
		throw;
		}
	}

	Image* fun_image(const std::string& Imfile = " ")
	{

		try
		{
			if (Imfile != " ")
			{
				return new Image;
				std::cout << "\n Image object is created";
			}
			else
				return 0;
		}
		catch (...)
		{
			//delete Theimage; // catches all exceptions.
			throw;
		}
	}

};


int main()
{
	catalogue c("Ram", "No-24B 12th cross st new colony chrompet", "rff");
	system("pause");
	return 0;
}
