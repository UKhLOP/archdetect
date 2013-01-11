extern const char* currentArchName()
{
#if defined(__arm__) || defined(__TARGET_ARCH_ARM)
    #if defined(__ARM_ARCH_7__) \
        || defined(__ARM_ARCH_7A__) \
        || defined(__ARM_ARCH_7R__) \
        || defined(__ARM_ARCH_7M__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM-0 >= 7)
        return "armv7";
    #elif defined(__ARM_ARCH_6__) \
        || defined(__ARM_ARCH_6J__) \
        || defined(__ARM_ARCH_6T2__) \
        || defined(__ARM_ARCH_6Z__) \
        || defined(__ARM_ARCH_6K__) \
        || defined(__ARM_ARCH_6ZK__) \
        || defined(__ARM_ARCH_6M__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM-0 >= 6)
        return "armv6";
    #elif defined(__ARM_ARCH_5TEJ__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM-0 >= 5)
        return "armv5";
    #else
        return "arm";
    #endif
#elif defined(__i386) || defined(__i386__) || defined(_M_IX86)
    return "i386";
#elif defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(_M_X64)
    return "x86_64";
#elif defined(__ia64) || defined(__ia64__) || defined(_M_IA64)
    return "ia64";
#elif defined(__ppc__) || defined(__ppc) || defined(__powerpc__) \
      || defined(_ARCH_COM) || defined(_ARCH_PWR) || defined(_ARCH_PPC)  \
      || defined(_M_MPPC) || defined(_M_PPC)
    #if defined(__ppc64__) || defined(__powerpc64__) || defined(__64BIT__)
        return "ppc64";
    #else
        return "ppc";
    #endif
#else
    return "unknown";
#endif
}