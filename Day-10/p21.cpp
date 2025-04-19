//10. Social Media Post Management

#include <iostream>
#include <vector>

class Post {
public:
    std::string content;
    int likes;

    Post(std::string c) : content(c), likes(0) {}

    void like() {
        likes++;
    }
};

class SocialMedia {
private:
    std::vector<Post> posts;

public:
    void addPost(const Post& post) {
        posts.push_back(post);
    }

    void displayPosts() const {
        for (const auto& post : posts) {
            std::cout << post.content << " - Likes: " << post.likes << "\n";
        }
    }
};