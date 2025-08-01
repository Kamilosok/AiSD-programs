#include <ios>
#include <vector>
#include <cstdint>
#include <set>
#include <cstring>

std::vector<uint16_t> patterns;
bool valid3Cols[32][32][32];

void printPattern(uint16_t pattern)
{
    for (size_t rowNum = 0; rowNum < 5; rowNum++)
    {
        for (size_t colNum = 0; colNum < 3; colNum++)
        {
            size_t bitToPrint = 5 * colNum + rowNum;
            uint16_t bitMask = 1 << bitToPrint;

            printf("%c", pattern & bitMask ? 'x' : '.');
        }
        printf("\n");
    }
}

// Passed in the 9 least significant bits, by row
void insertPattern3x3(uint16_t pattern3x3)
{
    uint16_t basePattern = 0;

    // Top pattern
    for (size_t i = 0; i < 3; i++)
    {
        basePattern = basePattern | (((pattern3x3 & (0b1 << 3 * i)) >> (3 * i)) | ((pattern3x3 & (0b1 << (1 + 3 * i))) >> (1 + 3 * i)) << 5 | ((pattern3x3 & (0b1 << (2 + 3 * i))) >> (2 + 3 * i)) << 10) << i;
    }

    for (size_t i = 0; i < 1 << 6; i++)
    {
        uint16_t fullPattern = 0;
        uint16_t fill = (uint16_t)i;

        for (size_t j = 0; j < 2; j++)
        {
            fullPattern = fullPattern | (((fill & (0b1 << 3 * j)) >> (3 * j)) | ((fill & (0b1 << (1 + 3 * j))) >> (1 + 3 * j)) << 5 | ((fill & (0b1 << (2 + 3 * j))) >> (2 + 3 * j)) << 10) << (j + 3);
        }

        fullPattern = fullPattern | basePattern;
        patterns.push_back(fullPattern);
    }

    // Middle pattern
    basePattern = 0;

    for (size_t i = 0; i < 3; i++)
    {
        basePattern = basePattern | (((pattern3x3 & (0b1 << 3 * i)) >> (3 * i)) | ((pattern3x3 & (0b1 << (1 + 3 * i))) >> (1 + 3 * i)) << 5 | ((pattern3x3 & (0b1 << (2 + 3 * i))) >> (2 + 3 * i)) << 10) << (i + 1);
    }

    for (size_t i = 0; i < 1 << 6; i++)
    {
        uint16_t fullPattern = 0;
        uint16_t fill = (uint16_t)i;

        for (size_t j = 0; j < 1; j++)
        {
            fullPattern = fullPattern | (((fill & (0b1 << 3 * j)) >> (3 * j)) | ((fill & (0b1 << (1 + 3 * j))) >> (1 + 3 * j)) << 5 | ((fill & (0b1 << (2 + 3 * j))) >> (2 + 3 * j)) << 10) << j;
        }

        for (size_t j = 1; j < 2; j++)
        {
            fullPattern = fullPattern | (((fill & (0b1 << 3 * j)) >> (3 * j)) | ((fill & (0b1 << (1 + 3 * j))) >> (1 + 3 * j)) << 5 | ((fill & (0b1 << (2 + 3 * j))) >> (2 + 3 * j)) << 10) << (j + 3);
        }

        fullPattern = fullPattern | basePattern;
        patterns.push_back(fullPattern);
    }

    basePattern = 0;

    // Bottom pattern
    for (size_t i = 0; i < 3; i++)
    {
        basePattern = basePattern | (((pattern3x3 & (0b1 << 3 * i)) >> (3 * i)) | ((pattern3x3 & (0b1 << (1 + 3 * i))) >> (1 + 3 * i)) << 5 | ((pattern3x3 & (0b1 << (2 + 3 * i))) >> (2 + 3 * i)) << 10) << (i + 2);
    }

    for (size_t i = 0; i < 1 << 6; i++)
    {
        uint16_t fullPattern = 0;
        uint16_t fill = (uint16_t)i;

        for (size_t j = 0; j < 2; j++)
        {
            fullPattern = fullPattern | (((fill & (0b1 << 3 * j)) >> (3 * j)) | ((fill & (0b1 << (1 + 3 * j))) >> (1 + 3 * j)) << 5 | ((fill & (0b1 << (2 + 3 * j))) >> (2 + 3 * j)) << 10) << j;
        }

        fullPattern = fullPattern | basePattern;
        patterns.push_back(fullPattern);
    }
}

inline bool check3Cols(const uint16_t col1, const uint16_t col2, const uint16_t col3)
{
    uint16_t full3Cols = col1 | (col2) << 5 | (col3) << 10;

    for (size_t i = 0; i < patterns.size(); i++)
    {
        if (full3Cols == patterns[i])
            return false;
    }

    return true;
}

uint32_t n, p, m;

// One column encodes 3×5 = 15 bits of information
// For each forbidden pattern, we store 2^6 × 3 possible column placements, by column
int main()
{
    std::ios::sync_with_stdio(false);

    uint64_t possibilities = 0;

    scanf("%u%u%u", &n, &p, &m);

    for (size_t i = 0; i < p; i++)
    {
        uint16_t pattern3x3 = 0;

        for (size_t j = 0; j < 3; j++)
        {
            char line[4];
            scanf(" %c%c%c", &line[0], &line[1], &line[2]);

            for (size_t l = 0; l < 3; l++)
            {
                line[l] = line[l] == 'x' ? 1 : 0;
            }

            pattern3x3 = pattern3x3 | (line[0] | (line[1] << 1) | (line[2] << 2)) << j * 3;
        }
        insertPattern3x3(pattern3x3);
    }

    std::vector<uint64_t> lastCols1;
    std::vector<uint64_t> lastCols2;
    uint64_t prevPosByCols[32][32];
    uint64_t currPosByCols[32][32];

    for (size_t i = 0; i < 32; i++)
    {
        for (size_t j = 0; j < 32; j++)
        {
            for (size_t k = 0; k < 32; k++)
            {
                valid3Cols[i][j][k] = check3Cols(i, j, k);
            }
        }
    }

    // Initially, we accept every valid pair of the first two columns
    for (uint16_t i = 0; i < 1 << 5; i++)
    {
        lastCols1.push_back(i);
        lastCols2.push_back(i);
    }

    memset(prevPosByCols, 0, sizeof(prevPosByCols));

    for (uint16_t first = 0; first < lastCols1.size(); first++)
    {
        for (uint16_t second = 0; second < lastCols2.size(); second++)
        {
            prevPosByCols[first][second] += 1;
        }
    }

    for (size_t i = 2; i < n; i++)
    {
        memset(currPosByCols, 0, sizeof(currPosByCols));
        std::set<uint16_t> currCols;

        for (uint16_t currCol = 0; currCol < 1 << 5; currCol++)
        {
            for (uint16_t first = 0; first < lastCols1.size(); first++)
            {
                for (uint16_t second = 0; second < lastCols2.size(); second++)
                {
                    if (valid3Cols[lastCols1[first]][lastCols2[second]][currCol])
                    {
                        currPosByCols[lastCols2[second]][currCol] += prevPosByCols[lastCols1[first]][lastCols2[second]] % m;
                        currCols.insert(currCol);
                    }
                }
            }
        }

        memcpy(prevPosByCols, currPosByCols, sizeof(currPosByCols));

        lastCols1 = std::move(lastCols2);
        lastCols2.insert(lastCols2.end(), currCols.begin(), currCols.end());
    }

    for (uint16_t first = 0; first < 32; first++)
    {
        for (uint16_t second = 0; second < 32; second++)
        {
            possibilities += prevPosByCols[first][second];
            possibilities = possibilities % m;
        }
    }

    printf("%lu\n", possibilities);

    return 0;
}