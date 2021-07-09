//
//

#ifndef PRACTICE_DATES_H
#define PRACTICE_DATES_H

struct date {
    int month, day, year;
};

int dayofYear(struct date d); // (a)
int compareDates(struct date d1, struct date d2); // (b)

#endif //PRACTICE_DATES_H
