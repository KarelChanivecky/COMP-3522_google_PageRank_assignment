/**
 * 10/2/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
 *
 * BCIT CST
 * Set O Datacomm
 * COMP - 3522
 *
 * Assignment 1
 */

#ifndef ASSIGNMENT1_V2_PAGE_HPP
#define ASSIGNMENT1_V2_PAGE_HPP

#include <utility>
#include <vector>
#include <string>

#define DEFAULT_NAME "wildcard"

using namespace std;

class Page {
private:
    string name;
    bool wildcard;
    vector<Page> linked_pages;
public:

    /**
     * Default constructor.
     */
    Page() : name{DEFAULT_NAME}, wildcard{true} {}

    /**
     * Construct and instance with no linked pages.
     * @param new_name the name of this page
     */
    explicit Page(string &new_name) : name{new_name}, wildcard{false} {}

    /**
     * Construct an instance with linked pages.
     * @param new_name the name of the page
     * @param links the pages that are linked to from this page
     */
    Page(string &new_name, vector<Page> links) : name{new_name}, wildcard{false}, linked_pages{std::move( links )} {}

    /**
     * Get the name of the page.
     * @return the name of the page
     */
    string get_name() const { return name; };

    /**
     * Get the pages that are linked-to from this page.
     * @return the pages that are linked-to from this page
     */
    vector<Page> get_links() const { return linked_pages; };


    /**
     * Determine if the Page is a wildcard.
     * @return true if the page is a wildcard, else false
     */
    bool is_wildcard() const { return wildcard; }

    /**
     * Evaluate if two given pages are equal
     * @param lhs a Page
     * @param rhs a Page
     * @return true if equal, else false
     */
    friend bool operator==(const Page &lhs, const Page &rhs);

    /**
     * Evaluate if two given pages are not equal
     * @param lhs a Page
     * @param rhs a Page
     * @return true if not equal, else false
     */
    friend bool operator!=(const Page &lhs, const Page &rhs);
};


#endif //ASSIGNMENT1_V2_PAGE_HPP
