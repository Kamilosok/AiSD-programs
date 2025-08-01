#include <array>
#include <cstdint>
#include <ios>
#include <stack>
#include <queue>
#include <vector>

static constexpr uint32_t MAX_N = 200000;
static constexpr uint32_t MAX_VAL = 100000;
static constexpr uint32_t DEAD_END = UINT32_MAX;

struct Brick
{
    uint32_t l = 0;
    uint32_t m = 0;
    uint32_t r = 0;

    // prev used not only to point to the previous brick, but also signal end of sidewalk (if points to self) or the first brick with DEAD_END
    uint32_t prev = DEAD_END;

    Brick() {}
    // Brick(uint32_t _l, uint32_t _m, uint32_t _r, uint32_t _prev) : l(_l), m(_m), r(_r), prev(_prev) {}
};

uint32_t n;
std::array<Brick, MAX_N + 1> lmr;
std::array<std::vector<uint32_t>, MAX_VAL + 1> dict;

void printPath(uint32_t endPath)
{
    if (endPath == DEAD_END)
    {
        printf("BRAK\n");
        return;
    }

    unsigned long long int sumLen = 1;
    long long unsigned int prev;
    prev = lmr[endPath].prev;

    // Prev not really needed in the queue
    std::stack<Brick> q;
    q.push(lmr[endPath]);

    if (prev == endPath)
    {
        printf("1\n%u %u %u\n", lmr[endPath].l, lmr[endPath].m, lmr[endPath].r);
        return;
    }

    while (prev != DEAD_END)
    {
        sumLen += 1;
        q.push(lmr[prev]);
        prev = lmr[prev].prev;
    }

    printf("%llu\n", sumLen);

    while (!q.empty())
    {
        Brick curr = q.top();
        q.pop();
        printf("%u %u %u\n", curr.l, curr.m, curr.r);
    }
}

uint32_t makePath()
{
    std::queue<uint32_t> zeros;

    // Initial bricks are ones, whose l are 0
    for (uint32_t i = 0; i < dict[0].size(); i++)
    {
        if (lmr[dict[0][i]].r == 0)
        {
            lmr[dict[0][i]].prev = i;
            return i;
        }

        zeros.push(dict[0][i]);
    }

    while (!zeros.empty())
    {
        std::queue<uint32_t> q;
        q.push(zeros.front());
        zeros.pop();
        while (!q.empty())
        {
            uint32_t currId = q.front();
            q.pop();
            uint32_t r = lmr[currId].r;
            if (r == 0)
                return currId;

            for (uint32_t i = 0; i < dict[r].size(); i++)
            {

                lmr[dict[r][i]].prev = currId;
                q.push(dict[r][i]);
                dict[r].erase(dict[r].begin() + i);
                i -= 1;
            }
        }
    }

    // If failed to reach the end
    return DEAD_END;
}

int main()
{
    std::ios::sync_with_stdio(false);

    scanf("%u", &n);

    for (uint32_t i = 0; i < n; i++)
    {
        scanf("%u%u%u", &lmr[i].l, &lmr[i].m, &lmr[i].r);
        dict[lmr[i].l].push_back(i);
    }

    printPath(makePath());

    return 0;
}