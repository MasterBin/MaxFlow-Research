#ifndef KDZ_PRJ_RDTSCTIMEMEASURER_HPP
#define KDZ_PRJ_RDTSCTIMEMEASURER_HPP

#import "TimeMeasurer.hpp"


template<typename ElementType>
class RDTSCTimeMeasurer : public TimeMeasurer<ElementType, uint64_t>
{
protected:

    void _startMeasure() override
    {
        asm volatile ("CPUID\n\t" "RDTSC\n\t"
                      "mov %%edx, %0\n\t"
                      "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
        "%rax", "%rbx", "%rcx", "%rdx");
    }

    uint64_t _endMeasure() override
    {
        asm volatile("RDTSCP\n\t"
                     "mov %%edx, %0\n\t" "mov %%eax, %1\n\t"
                     "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::
        "%rax", "%rbx", "%rcx", "%rdx");

        uint64_t end = (((uint64_t) cycles_high1 << 32) | cycles_low1);
        uint64_t start = (((uint64_t) cycles_high << 32) | cycles_low);
        return end - start;
    }

public:
    unsigned int cycles_high1, cycles_high, cycles_low, cycles_low1;
};

// SOURCE: https://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf


#endif //KDZ_PRJ_RDTSCTIMEMEASURER_HPP
