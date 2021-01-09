(defproject com.dedovic/triangle-clj "0.1.6"
  :description "A Triangle wrapper for Clojure"
  :url "https://github.com/sdedovic/jtriangle"
  :license {:name "Eclipse Public License 2.0"
            :url  "http://www.eclipse.org/legal/epl-2.0"}
  :dependencies [[org.clojure/clojure "1.10.1"]
                 [com.dedovic/jtriangle "0.1.6"]]
  :profiles {:dev {:dependencies [[org.clojure/clojure "1.10.0"]]}}

  :source-paths ["src/clj"]
  :java-source-paths ["src/java"]
  :resource-paths ["resources"]

  :deploy-repositories [["releases" :clojars]])
