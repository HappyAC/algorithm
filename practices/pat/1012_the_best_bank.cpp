#include <cstdio>
#include <algorithm>
struct gradeItem
{
    int id;
    int grade;
};
gradeItem avgGrades[2000], csGrades[2000], mathGrades[2000], englishGrades[2000];

bool cmp(gradeItem g1, gradeItem g2)
{
    return g1.grade > g2.grade;
}

int findRank(gradeItem grades[2000], int id, int n)
{
    int rank = 0, same = 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            if (grades[i].grade != grades[i - 1].grade)
            {
                rank += same;
                same = 1;
            }
            else
            {
                same++;
            }
        }

        if (grades[i].id == id)
        {
            return rank;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    int id, cs, math, english;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &id, &cs, &math, &english);
        csGrades[i].id = id;
        csGrades[i].grade = cs;
        mathGrades[i].id = id;
        mathGrades[i].grade = math;
        englishGrades[i].id = id;
        englishGrades[i].grade = english;
        int avg = (cs + math + english) / 3;
        avgGrades[i].id = id;
        avgGrades[i].grade = avg;
    }

    std::sort(csGrades, csGrades + n, cmp);
    std::sort(mathGrades, mathGrades + n, cmp);
    std::sort(englishGrades, englishGrades + n, cmp);
    std::sort(avgGrades, avgGrades + n, cmp);

    int qid;
    char rankNames[5] = "ACME";
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &qid);
        int ranks[4] = {
            findRank(avgGrades, qid, n),
            findRank(csGrades, qid, n),
            findRank(mathGrades, qid, n),
            findRank(englishGrades, qid, n)};

        if (ranks[0] == -1)
        {
            printf("N/A\n");
            continue;
        }
        int minRank = ranks[0];
        int minRankIndex = 0;

        for (int k = 1; k < 4; k++)
        {
            if (minRank > ranks[k])
            {
                minRank = ranks[k];
                minRankIndex = k;
            }
        }
        printf("%d %c\n", minRank + 1, rankNames[minRankIndex]);
    }
    return 0;
}