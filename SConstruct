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

src = Glob('build/*.cpp')
app = env.Program(target = buildDir + '/notebox', source = [src])
env.Install(distDir, app)

