using Imports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace MainNamespace
{
    public class LoaderClass
    {
        public static void RunAssemblyMain(Assembly assembly)
        {
            Type t = assembly.GetType("MainNamespace.MainClass");
            t.GetMethod("Main");
        }
        public static Assembly LoadAssembly(string filePath)
        {
            return Assembly.LoadFrom(filePath);
        }
        public static AppDomain CreateDomain(string name)
        {
            return AppDomain.CreateDomain(name);
        }
    }
}
namespace Imports
{
    public class ArkConsole
    {
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void AddLog(string s);
    }
}

