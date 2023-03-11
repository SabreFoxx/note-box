buildDir = 'build'
distDir = 'dist'
VariantDir(buildDir, 'src', duplicate=0)

env = Environment(
	COMPILATIONDB_USE_ABSPATH = True,
	CXXFLAGS = "-std=c++17 -Og",
	CPPPATH = ['dependencies/SFML-master/dist/include', 'src'],
	LIBPATH = ['dependencies/SFML-master/dist/lib'],
	LIBS = ['sfml-graphics-d',
			'sfml-network-d',
			'sfml-system-d',
			'sfml-window-d'
	]
)

# generate clang's compile_commands.json which we'll use to configure ide intellisense
env.Tool('compilation_db')
env.CompilationDatabase()

src = Glob('build/*.cpp')
app = env.Program(target = buildDir + '/notebox', source = [src])
env.Install(distDir, app)

