require 'rubygems'
require 'rbconfig'
require 'rake/clean'
require 'rake/packagetask'
require 'pathname'
require 'shellwords'

$buildTarget="Release" # "Debug"

include RbConfig

case CONFIG['host_os']
   when /mswin|windows|mingw32/i
      $HOST_OS = "windows"
   when /darwin/i
      $HOST_OS = "darwin"
   when /linux-gnu/i
      $HOST_OS = "linux"
   else
      abort("Unknown host config: Config::CONFIG['host_os']: #{Config::CONFIG['host_os']}")
end

if $HOST_OS == 'darwin'
  $numCores = Integer(`sysctl hw.ncpu | awk '{print $2}'`)
elsif $HOST_OS == 'windows'
  $numCores = ENV['NUMBER_OF_PROCESSORS']
else 
  $numCores = Integer(`cat /proc/cpuinfo | grep processor | wc -l`)
end

task :clobber do
  sh "git clean -fdx"
end

namespace :build do

  task :osx => ['build/luajit_x86/lib/libluajit-5.1.a'] do
      FileUtils.mkdir_p("cmake_osx")    
      Dir.chdir("cmake_osx") do
        sh "cmake ../ -G \"Unix Makefiles\" -DCMAKE_BUILD_TYPE=#{$buildTarget}"
        sh "make -j#{$numCores}"
      end
  end
end  

file 'build/luajit_x86/lib/libluajit-5.1.a' do 
    rootFolder = Dir.pwd 
    lua_jit_dir = File.join(rootFolder, "build", "luajit_x86")
    Dir.chdir("vendor/luajit") do
      sh "make clean"
      sh "make CC=\"gcc -m32\" PREFIX\"=#{lua_jit_dir.shellescape}\" -j#{$numCores}"
      sh "make CC=\"gcc -m32\" install PREFIX=\"#{lua_jit_dir.shellescape}\""
    end
end  

