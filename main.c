// branch testB2

#include <stdio.h>
#include <stdint.h>
#include "jsmn.h"
#include "logger.h"

jsmn_parser p;

#define		BUFFER_LEN			1024
#define     TOKEN_LIST_LEN      128
#define     TMP_STRING_LEN      128
#define     MESSAGE_HEADER      5

static const char *jsonStr1 =
"&*%$#{\
    \"type\": \"CREDENTIAL_ADDED\",\
    \"content\": {\
        \"credentialId\": \"11223344556677\",\
        \"credentialHolderId\": \"user1234\",\
        \"firstName\": \"Arnold\",\
        \"lastName\": \"Donald\",\
        \"major\": 8523\
        \"minor\": 3792\
        \"expireTime\": \"20170822T1544\"\
    }\
}";

static const char *jsonStr2 =
"&*%$#{\
  \"type\": \"CREDENTIAL_VERIFY\",\
  \"content\": {\
    \"credentialId\": \"11223344556677\",\
    \"data\": Tnl0ZWMgZG9lc24ndCBuZWVkIHRvIHBhcnNlIHRoaXMsIG9ubHkgZm9yd2FyZC4u,\
  }\
}";

static const char *jsonStr3 =
"&*%$#{\
  \"type\": \"LCU_STATUS_UPDATE\",\
  \"content\": {\
    \"doorId\": \"E222\",\
    \"batteryLevel\": 78,\
    \"doorState\": {\
      \"open\": false,\
      \"locked\": true,\
      \"deadBolted\": false\
    }\
  }\
}";

static const char *jsonStr4 =
"&*%$#{\
  \"type\": \"CREDENTIAL_WRITE\",\
  \"content\": {\
    \"credentialId\": \"11223344556677\",\
    \"data\": Tnl0ZWMgZG9lc24ndCBuZWVkIHRvIHBhcnNlIHRoaXMsIG9ubHkgZm9yd2FyZC4u,\
  }\
}";



void clearTokenList(jsmntok_t *t, int32_t tCount)
{
    int32_t index;
    
    for(index=0;index<tCount;index++)
    {
        t[index].type = 0;
        t[index].start = 0;
        t[index].end = 0;
        t[index].size = 0;
#ifdef JSMN_PARENT_LINKS
	    t[index].type = 0;
#endif
    }
     
}

int main(int argc, char **argv)
{
    int               tokenCount;
    static jsmntok_t  t[TOKEN_LIST_LEN];
    char              tmpStr[TMP_STRING_LEN];
    
	jsmn_init(&p);
    
    LOG_PRINT("***** Testing jsonStr1 *****\n");
    tokenCount = jsmn_parse(&p,jsonStr1+MESSAGE_HEADER , sizeof(jsonStr1)-MESSAGE_HEADER, t, TOKEN_LIST_LEN);  
    if(retrievJsonScriptValue(jsonStr1+MESSAGE_HEADER, t, tokenCount, "type", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "type", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr1+MESSAGE_HEADER, t, tokenCount, "credentialId", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "credentialId", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr1+MESSAGE_HEADER, t, tokenCount, "credentialHolderId", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "credentialHolderId", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr1+MESSAGE_HEADER, t, tokenCount, "data", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "data", tmpStr); 
        
    printf("\n");
    LOG_PRINT("***** Testing jsonStr2 *****\n");
    jsmn_init(&p);
    tokenCount = jsmn_parse(&p,jsonStr2+MESSAGE_HEADER , sizeof(jsonStr2)-MESSAGE_HEADER, t, TOKEN_LIST_LEN);  
    if(retrievJsonScriptValue(jsonStr2+MESSAGE_HEADER, t, tokenCount, "type", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "type", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr2+MESSAGE_HEADER, t, tokenCount, "credentialId", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "credentialId", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr2+MESSAGE_HEADER, t, tokenCount, "credentialHolderId", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "credentialHolderId", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr2+MESSAGE_HEADER, t, tokenCount, "data", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "data", tmpStr); 
    
    printf("\n");
    LOG_PRINT("***** Testing jsonStr3 *****\n");
    jsmn_init(&p);
    tokenCount = jsmn_parse(&p,jsonStr3+MESSAGE_HEADER , sizeof(jsonStr3)-MESSAGE_HEADER, t, TOKEN_LIST_LEN);  
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "type", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "type", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "doorId", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "doorId", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "batteryLevel", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "batteryLevel", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "doorState", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "doorState", tmpStr); 
        
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "open", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "open", tmpStr); 
        
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "locked", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "locked", tmpStr); 
        
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "deadBolted", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "deadBolted", tmpStr); 
        
    if(retrievJsonScriptValue(jsonStr3+MESSAGE_HEADER, t, tokenCount, "content", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "content", tmpStr); 
        
    
    printf("\n");
    LOG_PRINT("***** Testing jsonStr4 *****\n");
    jsmn_init(&p);
    tokenCount = jsmn_parse(&p,jsonStr4+MESSAGE_HEADER , sizeof(jsonStr4)-MESSAGE_HEADER, t, TOKEN_LIST_LEN);  
    if(retrievJsonScriptValue(jsonStr4+MESSAGE_HEADER, t, tokenCount, "type", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "type", tmpStr); 
        
    if(retrievJsonScriptValue(jsonStr4+MESSAGE_HEADER, t, tokenCount, "type", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "type", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr4+MESSAGE_HEADER, t, tokenCount, "credentialId", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "credentialId", tmpStr); 
    
    if(retrievJsonScriptValue(jsonStr4+MESSAGE_HEADER, t, tokenCount, "data", JS_STRING, (void *) tmpStr))
        LOG_PRINT("%s : %s\n", "data", tmpStr); 
        
	return 0;
}
