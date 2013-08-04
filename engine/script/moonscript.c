#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int luaopen_lpeg (lua_State *L);
int luaopen_lfs (lua_State *L);

// put whatever is on top of stack into package.loaded under name something is
// already there

static void setloaded(lua_State* l, char* name) 
{
	int top = lua_gettop(l);
	
	lua_getglobal(l, "package");
	lua_getfield(l, -1, "loaded");
	lua_getfield(l, -1, name);

	if (lua_isnil(l, -1)) 
	{
		lua_pop(l, 1);
		lua_pushvalue(l, top);
		lua_setfield(l, -2, name);
	}

	lua_settop(l, top);
}

int Script_Init() 
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	luaopen_lpeg(l);
	setloaded(l, "lpeg");
	luaopen_lfs(l);
	setloaded(l, "lfs");
}
