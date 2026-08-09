#ifndef _CUTILS_MULTIUSER_H
#define _CUTILS_MULTIUSER_H

#include <sys/types.h>
#include <unistd.h>

#define AID_USER_OFFSET 100000
#define AID_APP_START 10000
#define AID_APP_END 19999
#define AID_SHARED_GID_START 50000
#define AID_SHARED_GID_END 59999

typedef uid_t userid_t;

static inline uid_t multiuser_get_uid(uid_t uid, userid_t user_id)
{
    return (user_id * AID_USER_OFFSET) + (uid % AID_USER_OFFSET);
}

static inline userid_t multiuser_get_user_id(uid_t uid)
{
    return uid / AID_USER_OFFSET;
}

static inline uid_t multiuser_get_app_id(uid_t uid)
{
    return uid % AID_USER_OFFSET;
}

static inline int multiuser_get_sdk_version(uid_t uid)
{
    return uid % AID_USER_OFFSET;
}

#endif
