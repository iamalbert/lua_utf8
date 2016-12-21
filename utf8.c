#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int numberOfBytesInChar(unsigned char val) {
    if (val < 128) {
        return 1;
    } else if (val < 224) {
        return 2;
    } else if (val < 240) {
        return 3;
    } else {
        return 4;
    }
}


static int utf8_split(lua_State *L){
    const char * string = luaL_checkstring(L, 1);
    size_t i = 0, num = 0;
    lua_newtable(L);

    while( string[i] != '\0' ){
        int n = numberOfBytesInChar(string[i]);

        // key
        num += 1;
        lua_pushinteger(L, num);

        //value
        lua_pushlstring(L, string + i, n);

        lua_rawset(L, -3);
        i += n;
    }
    return 1;
}
int luaopen_utf8(lua_State *L){
    lua_pushcfunction(L, utf8_split);
    return 1;
}
