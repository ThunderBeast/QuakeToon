require 'rubygems'
require 'rbconfig'
require 'rake/clean'
require 'rake/packagetask'
require 'pathname'
require 'shellwords'

$buildTarget="Release" # "Debug"

$numCores = Integer(`sysctl hw.ncpu | awk '{print $2}'`)

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

