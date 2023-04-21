buildDir = 'build'
distDir = 'dist'
VariantDir(buildDir, 'src', duplicate=0)

env = Environment(
	COMPILATIONDB_USE_ABSPATH = True,
	CXXFLAGS = "-std=c++17 -Og",
	CPPPATH = [
		'dependencies/SFML-master/dist/include',
		'dependencies/fruit-3.7.1/dist/include',
		'src'
	],
	LIBPATH = ['dependencies/SFML-master/dist/lib', 'dependencies/fruit-3.7.1/dist/lib'],
	LIBS = [
		'sfml-graphics-d',
		'sfml-network-d',
		'sfml-system-d',
		'sfml-window-d',
		'fruit'
	]
)

# generate clang's compile_commands.json which we'll use to configure ide intellisense
env.Tool('compilation_db')
env.CompilationDatabase()

filemanager = Glob(buildDir + '/filemanager/**/*.cpp')
drawing = Glob(buildDir + '/drawing/**/*.cpp')
dependencyInjection = Glob(buildDir + '/di/*.cpp')
main = [buildDir + '/main.cpp', buildDir + '/app.cpp']
app = env.Program(target = buildDir + '/notebox', source = [main, filemanager, drawing, dependencyInjection])
env.Install(distDir, app)

