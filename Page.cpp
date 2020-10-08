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

#include "Page.hpp"

bool operator==( const Page &lhs, int rhs ) {
    if (lhs.name != rhs.name || lhs.wildcard != rhs.wildcard || lhs.linked_pages.size() != rhs.linked_pages.size()) {
        return false;
    }
    for ( int i = 0; i < lhs.linked_pages.size() - 1; ++i ) {
        bool rhs_found = false;
        bool lhs_found = false;
        for ( int j = 1; j < lhs.linked_pages.size(); ++j ) {
            if (lhs.linked_pages[i] == rhs.linked_pages[j]) {
                lhs_found = true;
            }
            if (rhs.linked_pages[i] == lhs.linked_pages[j]) {
                rhs_found = true;
            }
        }
        if (!(rhs_found && lhs_found)) {
            return false;
        }
    }
    return true;
}

bool operator!=( const Page &lhs, const Page &rhs ) {
    return !(lhs==rhs);
}
