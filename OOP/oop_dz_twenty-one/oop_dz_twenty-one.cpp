#include <iostream>
#include "RepositoryArray.h"
#include "RepositoryList.h"
#include "Repository.h"

int main()
{
	//while (true)
	{
		File* image = new Image{ ".png", 5, "1920x1080" };
		File* video = new Video{ ".mp4", 10, 45 };
		File* audio = new Audio{ ".mp3", 8, 140, 512, "The Weeknd", "Blinding Lights" };
		Repository repos;
		repos.add(image);
		repos.add(video);
		repos.add(audio);
		if (repos[0] == image && repos[1] == video && repos[2] == audio)
		{
			std::cout << "With repository based on dymanic memory everything is fine!" << '\n';
		}
		repos.remove(image);
		repos.remove(video);
		repos.remove(audio);
	}
	//while(true)
	{
		File* image = new Image{ ".png", 5, "1920x1080" };
		File* video = new Video{ ".mp4", 10, 45 };
		File* audio = new Audio{ ".mp3", 8, 140, 512, "The Weeknd", "Blinding Lights" };
		RepositoryArray repos;
		repos.add(image);
		repos.add(video);
		repos.add(audio);
		if (repos[0] == image && repos[1] == video && repos[2] == audio)
		{
			std::cout << "With repository based on Array<T> class everything is fine!" << '\n';
		}
		repos.remove(image);
		repos.remove(video);
		repos.remove(audio);
	}
	//while(true)
	{
		File* image = new Image{ ".png", 5, "1920x1080" };
		File* video = new Video{ ".mp4", 10, 45 };
		File* audio = new Audio{ ".mp3", 8, 140, 512, "The Weeknd", "Blinding Lights" };
		RepositoryList repos;
		auto image_node = repos.add(image);
		auto video_node = repos.add(video);
		auto audio_node = repos.add(audio);
		if (repos[0] == image && repos[1] == video && repos[2] == audio)
		{
			std::cout << "With repository based on LinkedList<T> class everything is fine!" << '\n';
		}
		repos.remove(image_node);
		repos.remove(video_node);
		repos.remove(audio_node);
	}
}

