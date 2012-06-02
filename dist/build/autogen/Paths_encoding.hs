module Paths_encoding (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName
  ) where

import Data.Version (Version(..))
import System.Environment (getEnv)

version :: Version
version = Version {versionBranch = [0,6,5], versionTags = []}

bindir, libdir, datadir, libexecdir :: FilePath

bindir     = "/home/karl/.cabal/bin"
libdir     = "/home/karl/.cabal/lib/encoding-0.6.5/ghc-7.0.3"
datadir    = "/home/karl/.cabal/share/encoding-0.6.5"
libexecdir = "/home/karl/.cabal/libexec"

getBinDir, getLibDir, getDataDir, getLibexecDir :: IO FilePath
getBinDir = catch (getEnv "encoding_bindir") (\_ -> return bindir)
getLibDir = catch (getEnv "encoding_libdir") (\_ -> return libdir)
getDataDir = catch (getEnv "encoding_datadir") (\_ -> return datadir)
getLibexecDir = catch (getEnv "encoding_libexecdir") (\_ -> return libexecdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
